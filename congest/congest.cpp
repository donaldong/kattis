#include <bits/stdc++.h>
using namespace std;

#define hset unordered_set
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

struct edge;

struct node {
  // Edges
  vector<edge*> E;
  // number of comuters
  int c;
  // total time
  ull tt = -1;
  // time to sink
  ull tts;
  // edge in the path
  edge *e;
};

struct edge {
  node *src, *dest;
  // time
  ull t;
  // Time table
  hset<ull> T;

  edge(node *src, node *dest, ull t) : 
    src(src),
    dest(dest),
    t(t) {}
};

struct node_cmp {
  bool operator() (node *a, node *b) const {
    if (a->tt != b->tt) return a->tt < b->tt;
    return a < b;
  }
};

vector<node> N;

void dijkstra(node *src) {
  set<node*, node_cmp> Q;
  src->tt = 0;
  Q.insert(src);
  while (!Q.empty()) {
    auto itr = Q.begin();
    auto cur = *itr;
    Q.erase(itr);
    for (auto e : cur->E) {
      // new total time
      ull ntt = e->t + cur->tt;
      auto dest = e->dest;
      if (ntt < dest->tt) {
        itr = Q.find(dest);
        if (itr != Q.end()) Q.erase(itr);
        dest->tt = ntt;
        Q.insert(dest);
      }
    }
  }
}

node* bfs() {
  node *src;
  for (size_t i = 1; i < N.size(); ++i) {
    src = &N[i];
    if (!src->c) continue;
    queue<node*> Q;
    Q.push(src);
    while (!Q.empty()) {
      auto cur = Q.front();
      auto t = cur->tts;
      Q.pop();
      for (auto e : cur->E) {
        auto dest = e->dest;
        // continue if not an optimal path
        if (cur->tt != dest->tt + e->t) continue; 
        // continue if the road is used
        if (e->T.find(t) != e->T.end()) continue;
        dest->tts = t + e->t;
        dest->e = e;
        if (dest == &N[0]) return src;
        Q.push(dest);
      }
    }
  }
  return 0;
}

int max_flow() {
  int res = 0;
  while (true) {
    node *cur = bfs();
    if (!cur) return res;
    --cur->c;
    cur->e = 0;
    auto t = &N[0];
    while (t->e) {
      t->e->T.insert(t->e->src->tts);
      t = t->e->src;
    }
    ++res;
  }
  return res;
}

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  N = vector<node>(n);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    N[a].E.push_back(new edge(&N[a], &N[b], c));
    N[b].E.push_back(new edge(&N[b], &N[a], c));
  }
  while (c--) {
    int k;
    cin >> k;
    --k;
    N[k].c++;
  }
  dijkstra(&N[0]);
  cout << max_flow() + N[0].c << endl;
  return 0;
}
