#include <bits/stdc++.h>
using namespace std;

struct node {
  // total number of marbles
  int tm = 0;
  // total number of nodes 
  int tn = 1;
  // number of marbles
  int m = 0;
  // Children
  vector<node*> C;
  // Parent
  node* p = 0;
};

void build(node* n) {
  n->tm = n->m;
  for (auto c : n->C) {
    build(c);
    n->tm += c->tm;
    n->tn += c->tn;
  }
}

int solve(node *n) {
  int res = 0;
  for (auto c : n->C) {
    int move = c->tm - c->tn;
    res += abs(move);
    n->m += move;
    c->m -= move;
  }
  for (auto c : n->C) res += solve(c);
  return res;
}

int main() {
  int N;
  while (cin >> N) {
    if (!N) break;
    vector<node> nodes(N);
    while (N--) {
      int v, m, d, u;
      cin >> v >> m >> d;
      --v;
      nodes[v].m = m;
      while (d--) {
        cin >> u;
        --u;
        nodes[v].C.push_back(&nodes[u]);
        nodes[u].p = &nodes[v];
      }
    }
    node *root;
    for (auto &n : nodes) {
      if (!n.p) {
        root = &n;
        break;
      }
    }
    build(root);
    cout << solve(root) << endl;
  }
  return 0;
}
