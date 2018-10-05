#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
int INF = 1e9;

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
  pt(const pt &p) : x(p.x), y(p.y) {}
};

pt TL(INF, -INF), TR(-INF, -INF), BR(-INF, INF), BL(INF, INF);

struct region {
  // top-left, top-right, bottom-right, bottom-left
  vector<pt> P;
  region() {}
  region(pt p) {
    P.push_back(p);
  }
  int exclude(int e) {
    bool f = false;
    int max_x = -INF, max_y = -INF, min_x = INF, min_y = INF;
    for (size_t i = 0; i < P.size(); ++i) {
      if (i == e) continue;
      f = true;
      max_x = max(max_x, P[i].x);
      max_y = max(max_y, P[i].y);
      min_x = min(min_x, P[i].x);
      min_y = min(min_y, P[i].y);
    }
    if (!f) return 0;
    return max(max_x - min_x, max_y - min_y);
  }
};

void find_bound(vector<pt> &B, vi &pos, vb &M) {
  pt tl(TL), tr(TR), br(BR), bl(BL);
  for (size_t i = 0; i < B.size(); ++i) {
    if (M[i]) continue;
    if (B[i].x <= tl.x && B[i].y >= tl.y) pos[0] = i, tl = B[i];
    if (B[i].x >= tr.x && B[i].y >= tr.y) pos[1] = i, tr = B[i];
    if (B[i].x >= br.x && B[i].y <= br.y) pos[2] = i, br = B[i];
    if (B[i].x <= bl.x && B[i].y <= bl.y) pos[3] = i, bl = B[i];
  }
  for (int p : pos) if (p >= 0) M[p] = true;
}

void debug(vi &v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void debug(const pt &p) {
  printf("[%d,%d] ", p.x, p.y);
}

void debug(const region &reg) {
  for (size_t i = 0; i < reg.P.size(); ++i) debug(reg.P[i]);
  cout << endl;
}

void debug(vector<pt> &B) {
  for (auto &b : B) debug(b);
  cout << endl;
}

struct node {
  region reg;
  int i = -1, a, b;
  bool f = true;
  node *l = 0, *r = 0;
  node() {}
  node(node *n) : reg(n->reg) {
    f = n->f;
  }
  node(int i) : i(i) {
    a = b = i;
  }
  void merge(const region &nr) {
    if (f) {
      reg = nr;
      f = false;
      return;
    }
    vector<pt> B(reg.P.size() + nr.P.size());
    vb M(B.size(), false);
    for (size_t i = 0; i < reg.P.size(); ++i) B[i] = reg.P[i];
    for (size_t i = 0; i < nr.P.size(); ++i) B[i + reg.P.size()] = nr.P[i];
    vi outer(4, -2), inner(4, -2);
    find_bound(B, outer, M);
    find_bound(B, inner, M);
    vi uid;
    auto itr = uid.insert(uid.begin(), outer.begin(), outer.end());
    uid.insert(itr, inner.begin(), inner.end());
    sort(uid.begin(), uid.end());
    itr = unique(uid.begin(), uid.end());
    uid.resize(itr - uid.begin());
    reg.P.clear();
    for (size_t i = 0; i < uid.size(); ++i) {
      if (uid[i] < 0) continue;
      reg.P.push_back(B[uid[i]]);
    }
  }
  int min_side() {
    int res = INF;
    for (size_t i = 0; i < reg.P.size(); ++i) {
      res = min(res, reg.exclude(i)); 
    }
    return res;
  }
  bool in_range(int i) {
    return a <= i && i <= b;
  }
};

void print_space(int n) {
  while (n--) cout << ' ';
}

void debug(node *n, int space=0) {
  print_space(space);
  cout << n->f << " ";
  cout << n->a << " " << n->b << endl;
  print_space(space);
  cout << "bound: ";
  for (size_t i = 0; i < n->reg.P.size(); ++i) debug(n->reg.P[i]);
  cout << endl;
  if (n->l) {
    print_space(space);
    cout << "L" << endl;
    debug(n->l, space + 2);
  }
  if (n->r) {
    print_space(space);
    cout << "R" << endl;
    debug(n->r, space + 2);
  }
}

node* build(int n) {
  vector<node*> F, B;
  F.reserve(n); B.reserve(n);
  for (size_t i = 0; i < n; ++i) {
    F.push_back(new node(i));
  }
  while (F.size() != 1) {
    B.clear();
    for (size_t i = 0; i < F.size(); i += 2) {
      if (i + 1 == F.size()) {
        B.push_back(F.back());
        break;
      }
      node *a = F[i], *b = F[i + 1];
      node *c = new node(a);
      c->l = a, c->r = b;
      c->a = a->a;
      c->b = b ? b->b : a->b;
      B.push_back(c);
    }
    swap(F, B);
  }
  return F[0];
}

node query(node *n, int a, int b) {
  if (a <= n->a && n->b <= b) return node(n);
  node res; 
  if (n->l && a <= n->l->b) res.merge(query(n->l, a, n->l->b).reg);
  if (n->r && n->r->a <= b) res.merge(query(n->r, n->r->a, b).reg);
  return res;
}

void update(node *n, int i, region &r) {
  n->merge(r);
  if (n->l && n->l->in_range(i)) update(n->l, i, r);
  else if (n->r && n->r->in_range(i)) update(n->r, i, r);
}

int main() {
  int n, q, x, y, a, b;
  cin >> n >> q;
  auto root = build(n);
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    region new_region(pt(x, y));
    update(root, i, new_region);
  }
  while (q--) {
    cin >> a >> b;
    cout << query(root, --a, --b).min_side() << endl;
  }
  return 0;
}
