#include <bits/stdc++.h>
using namespace std;

struct node {
  node *p = 0;
  // identifier
  int r = -1;
  // children
  vector<node*> C;
  // total number of nodes in the subtree
  int t = 0;
  // count
  int k = 0;
};

struct cmp {
  bool operator()(node *a, node *b) {
    size_t n = a->C.size(), m = b->C.size();
    if (n != m) return n < m;
    return a < b;
  }
};

using vn = vector<node*>;
using sn = set<node*, cmp>;
using vi = vector<int>;

void build(node *cur) {
  for (auto c : cur->C) {
    build(c);
    cur->t += c->t;
  }
  ++cur->t;
}

void update(sn &S) {
  while (!S.empty()) {
    auto cur = *S.begin();
    S.erase(S.begin());
    auto itr = S.find(cur);
    while (itr == S.end()) {
      ++cur->k;
      cur = cur->p; 
      itr = S.find(cur);
    }
    S.erase(itr);
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
    sn S;
    while (s--) {
      int k;
      cin >> k;
      S.insert(N[--k]);
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
