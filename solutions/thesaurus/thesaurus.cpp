#include <bits/stdc++.h>
using namespace std;

struct node;

using vs = vector<string>;
using vn = vector<node*>;
using hmap = unordered_map<string, node*>;

hmap M;

struct node {
  bool visited;
  size_t length;
  node *p;

  node() {}
  node(string &str) {
    length = str.size();
    p = this;
  }
};

node* get_node(string &s) {
  if (M.find(s) != M.end()) return M[s];
  M[s] = new node(s);
  return M[s];
}

node *find(node *n) {
  if (n->p != n) {
    n->p = find(n->p);
  }
  return n->p;
}

void join(node *a, node *b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (a->length <= b->length) {
    b->p = a;
  } else if (a->length > b->length) {
    a->p = b;
  }
}

void connect(node *a, node *b) {
  auto ra = find(a);
  auto rb = find(b);
  if (ra != rb) join(a, b);
}

size_t solve(vs &N) {
  size_t res = 0;
  for (auto &word : N) {
    res += find(get_node(word))->length;
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
