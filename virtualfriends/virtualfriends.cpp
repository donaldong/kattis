#include <bits/stdc++.h>
using namespace std;

struct node {
  node *p;
  int r = 1;
};

using hmap = unordered_map<string, node*>;

node* get_node(hmap &M, string &s) {
  if (M.find(s) != M.end()) return M[s];
  auto n = new node();
  n->p = n; M[s] = n;
  return n;
}

node* find(node *n) {
  if (n->p != n) n->p = find(n->p);
  return n->p;
}

void join(node *a, node *b) {
  if (a->r <= b->r) {
    a->p = b;
    b->r += a->r;
  } else {
    b->p = a;
    a->r += b->r;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, q;
  cin >> t;
  while (t--) {
    cin >> q;
    hmap M;
    string A, B;
    while (q--) {
      cin >> A >> B;
      auto a = get_node(M, A);
      auto b = get_node(M, B);
      auto ra = find(a);
      auto rb = find(b);
      if (ra != rb) join(ra, rb);
      cout << find(ra)->r << endl;
    }
    for (auto &entry : M) delete entry.second;
  }
  return 0;
}
