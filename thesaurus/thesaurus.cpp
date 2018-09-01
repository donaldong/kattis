#include <bits/stdc++.h>
using namespace std;

struct node;

using vs = vector<string>;
using vn = vector<node*>;
using hmap = unordered_map<string, node*>;

hmap M;

struct node {
  vn neigh;
  bool visited;
};

node* get_node(string &s) {
  if (M.find(s) != M.end()) return M[s];
  M[s] = new node();
  return M[s];
}

void connect(node *a, node *b) {
  a->
}

int main() {
  int n, m;
  cin >> n >> m;
  vs N(n);
  for (auto &e : N) cin >> e;
  while (m--) {
    string a, b;
    cin >> a >> b;
    auto na = get_node(a);
    auto nb = get_node(b);
    connect(na, nb);
  }
  cout << solve(N) << endl;
  return 0;
}
