#include <bits/stdc++.h>
using namespace std;

struct node;
using vn = vector<node*>;
using vi = vector<int>;
using hsn = unordered_set<node*>;

struct node {
  node *p = 0;
  // identifier
  int r = -1;
  // children
  vector<node*> C;
  // subtree
  hsn T;
  // count
  int k = 0;
  bool visited = false;
};

void build(node *n) {
  n->visited = true;
  for (auto &c : n->C) {
    if (c->visited) {
      c = 0;
      continue;
    }
    c->p = n;
    build(c);
    for (auto e : c->T) n->T.insert(e);
  }
  n->T.insert(n);
}

bool subset(vn &S, node *n) {
  for (auto cur : S) {
    if (n->T.find(cur) == n->T.end()) return false;
  }
  return true;
}

node* lca(vn &S, node *n) {
  for (auto c : n->C) {
    if (!c) continue;
    if (!subset(S, c)) return n;
    return lca(S, c);
  }
  return n;
}

void update(vn &S, node *root) {
  root = lca(S, root);
  for (auto cur : S) {
    while (cur != root) {
      cur->visited = false;
      cur = cur->p;
    }
  }
  for (auto cur : S) {
    while (cur != root) {
      if (cur->visited) break;
      cur->visited = true;
      ++cur->k;
      cur = cur->p;
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vn N(n);
  for (auto &e : N) e = new node();
  vector<tuple<int, int>> E(n - 1);
  for (size_t i = 0; i < E.size(); ++i) {
    int a, b;
    cin >> a >> b;
    E[i] = make_tuple(--a, --b);
    auto na = N[a];
    auto nb = N[b];
    na->C.push_back(nb);
    nb->C.push_back(na);
  }
  // rooted at node 0
  build(N[0]);
  for (size_t i = 0; i < E.size(); ++i) {
    int a, b;
    tie(a, b) = E[i];
    auto na = N[a];
    auto nb = N[b];
    if (na->p == nb) na->r = i + 1;
    else nb->r = i + 1;
  }
  while (m--) {
    int s;
    cin >> s;
    vn S(s);
    for (auto &e : S) {
      int k;
      cin >> k;
      e = N[--k];
    }
    update(S, N[0]);
  }
  vi res;
  for (auto e : N) if (e->k >= k) res.push_back(e->r);
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int r : res) cout << r << " ";
  cout << endl;
  return 0;
}
