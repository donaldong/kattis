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
  size_t length;
  size_t min_length = -1;
  node() {}
  node(string &str) {
    length = str.size();
  }
};

node* get_node(string &s) {
  if (M.find(s) != M.end()) return M[s];
  M[s] = new node(s);
  return M[s];
}

void connect(node *a, node *b) {
  a->neigh.push_back(b);
  b->neigh.push_back(a);
}

size_t dfs(node *n) {
  if (n->min_length != -1) return n->min_length;
  n->min_length = min(n->min_length, n->length);
  for (auto c : n->neigh) {
    n->min_length = min(n->min_length, dfs(c));
  }
  return n->min_length;
}

size_t solve(vs &N) {
  size_t res = 0;
  for (auto &word : N) {
    res += dfs(get_node(word));
  }
  return res;
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
