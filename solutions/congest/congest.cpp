#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map
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
  // edge in the augmenting path
  edge *e;
  // flag for visited
  bool f = false;
  // index
  int i;
};

struct edge {
  node *src, *dest;
  // time
  ull t;

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

struct flow_edge {
  int flow;
  node *src, *dest;
  int rev;
  flow_edge(node *src, node *dest, int flow) :
    src(src), dest(dest), flow(flow) {}
};

struct flow_net {
  // visited
  vector<bool> V;
  vector<vector<flow_edge>> M;
  // parents
  vector<pair<int, int>> P;
  
  flow_net(size_t n) : M(n), V(n, false), P(n) {}

  void connect(node *src, node *from, int flow) {
    flow_edge a(src, from ,flow), b(from, src, 0);
    b.rev = M[src->i].size();
    a.rev = M[from->i].size();
    M[src->i].push_back(a);
    M[from->i].push_back(b);
  }

  void unmark() {
    fill(V.begin(), V.end(), false);
  }

  void mark(node *n) {
    V[n->i] = true;
  }

  bool marked(node *n) {
    return V[n->i];
  }

  vector<flow_edge> E(node *n) {
    return M[n->i];
  }
};

flow_net build() {
  flow_net res(N.size() + 1);
  res.P.back() = make_pair(-1, -1);
  queue<node*> Q;
  Q.push(&N[0]);
  N[0].f = true;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (auto e : cur->E) {
      auto dest = e->dest;
      if (cur->tt + e->t == dest->tt) {
        res.connect(dest, cur, 1);
      }
      if (!dest->f) {
        dest->f = true;
        Q.push(dest);
      }
    }
  }
  return res;
}

bool bfs(flow_net &fn, node *s, node *t) {
  fn.unmark();
  queue<node*> Q;
  Q.push(s);
  fn.mark(s);
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    auto E = fn.E(cur);
    for (size_t i = 0; i < E.size(); ++i) {
      auto dest = E[i].dest;
      if (fn.marked(dest) || E[i].flow == 0) continue;
      fn.P[dest->i] = make_pair(cur->i, i);
      fn.mark(dest);
      Q.push(dest);
    }
  }
  return fn.marked(t);
}

int dfs(flow_net &fn, node *t) {
  int res = N.size();
  int cur = t->i;
  while (true) {
    int p = fn.P[cur].first;
    int j = fn.P[cur].second;
    if (p == -1) break;
    auto &e = fn.M[p][j];
    res = min(res, e.flow);
    cur = p;
  }
  cur = t->i;
  while (true) {
    int p = fn.P[cur].first;
    int j = fn.P[cur].second;
    if (p == -1) break;
    auto &e = fn.M[p][j];
    e.flow -= res;
    fn.M[cur][e.rev].flow += res;
    cur = p;
  }
  return res;
}

int max_flow(flow_net fn, vector<node*> &vec) {
  node *s = new node();
  s->i = N.size();
  node *t = &N[0];
  for (auto n : vec) {
    fn.connect(s, n, 1);
  }
  int res = 0;
  while (bfs(fn, s, t)) {
    res += dfs(fn, t);
  }
  delete s;
  return res;
}

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  N = vector<node>(n);
  for (int i = 0; i < n; ++i) N[i].i = i;
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
  flow_net fn = build();
  hmap<ull, vector<node*>> T;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < N[i].c; ++j) {
      T[N[i].tt].push_back(&N[i]);
    }
  }
  int res = 0;
  for (auto &entry : T) {
    res += max_flow(fn, entry.second);
  }
  cout << res << endl;
  return 0;
}
