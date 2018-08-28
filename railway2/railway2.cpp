#include <bits/stdc++.h>
using namespace std;

struct node {
  node *p = 0;
  // identifier
  int r = -1;
  // children
  vector<node*> C;
  // count
  int k = 0;
  // depth
  int d = 0;
  bool visited = false;
};

using vn = vector<node*>;
using vi = vector<int>;
using hsn = unordered_set<node*>;

void build(node *n) {
  for (auto c : n->C) {
    c->d = n->d + 1;
    build(c);
  }
}

node* lca(vn &S) {
  int d = 1e9;
  for (auto s : S) d = min(d, s->d);
  hsn N;
  for (auto s : S) if (s->d == d) N.insert(s);
  while (N.size() > 1) {
    hsn P;
    for (auto n : N) P.insert(n);
    N = P;
  }
  return *N.begin();
}

void update(vn &S) {
  auto root = lca(S);
  for (auto cur : S) {
    while (cur != root) {
      if (cur->visited) break;
      cur->visited = true;
      ++cur->k;
      cur = cur->p;
    }
  }
  for (auto cur : S) {
    while (cur != root) {
      cur->visited = false;
      cur = cur->p;
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vn N(n);
  for (auto &e : N) e = new node();
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    auto na = N[--a];
    auto nb = N[--b];
    if ((!na->p && !nb->p) || na->p) {
      nb->p = na;
      nb->r = i;
      na->C.push_back(nb);
    } else {
      na->p = nb;
      na->r = i;
      nb->C.push_back(na);
    }
  }
  // rooted at node 0
  build(N[0]);
  while (m--) {
    int s;
    cin >> s;
    vn S(s);
    for (auto &e : S) {
      int k;
      cin >> k;
      e = N[--k];
    }
    update(S);
  }
  vi res;
  for (auto e : N) if (e->k >= k) res.push_back(e->r);
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int r : res) cout << r << " ";
  cout << endl;
  return 0;
}
