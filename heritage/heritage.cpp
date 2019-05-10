#include <bits/stdc++.h>
using namespace std;

struct node;

typedef long long ll;
typedef vector<int> vi;
typedef vector<node*> vn;

struct node {
  vn children;
  int meanings, word_length;
  node(int m=0, int l=0) : children(26, 0), meanings(m), word_length(l) {}
};

int MOD = 1e9 + 7;
node *root;
string W;
unordered_map<node*, vi> DP;

void build(node *n, string &w, int i, int m) {
  auto &c = n->children[w[i] - 'a'];
  if (!c) c = new node;
  if (i + 1 == w.size()) {
    c->meanings = m, c->word_length = w.size();
    return;
  }
  build(c, w, i + 1, m);
}

void get_nodes(node *n, int i, vn &nodes) {
  if (i >= W.size()) return;
  auto &c = n->children[W[i] - 'a'];
  if (!c) return;
  if (c->word_length) nodes.push_back(c);
  get_nodes(c, i + 1, nodes);
}

int solve(node *n, int i) {
  if (i == W.size()) return n->meanings;
  if (DP.find(n) == DP.end()) DP[n] = vi(W.size(), -1);
  auto &mem = DP[n];
  if (mem[i] >= 0) return mem[i];
  vn nodes;
  get_nodes(root, i, nodes);
  ll res = 0;
  for (auto c : nodes) {
    res += solve(c, i + c->word_length);
    res %= MOD;
  }
#ifdef DEBUG
  printf("%d: %d * %lld\n", i, n->meanings, res);
#endif
  res = (res * n->meanings) % MOD;
  mem[i] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> W;
  string w;
  root = new node(1, 0);
  while (n--) {
    cin >> w >> m;
    build(root, w, 0, m);
  }
  printf("%d\n", solve(root, 0));
  return 0;
}
