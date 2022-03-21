#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int INF = 5e8;
vector<queue<int>> Q;
unordered_set<int> cache;
map<int, int> reuse_dist;

void cache_update(int i) {
  for (auto itr = reuse_dist.begin(); itr != reuse_dist.end() && itr->first <= i;) {
    if (!cache.count(itr->second)) {
      itr = reuse_dist.erase(itr);
      continue;
    }
    auto &q = Q[itr->second];
    q.pop();
    if (!q.empty()) reuse_dist[q.front()] = itr->second;
    itr = reuse_dist.erase(itr);
  }
}

void cache_insert(int ele, bool evict=1) {
  if (!reuse_dist.empty() && evict) {
    auto itr = --reuse_dist.end();
    for (; !cache.count(itr->second);) itr = --reuse_dist.erase(itr);
    cache.erase(itr->second);
    reuse_dist.erase(itr);
  }
  cache.insert(ele);
  reuse_dist[Q[ele].front()] = ele;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int c, n, a, reads = 0;
  cin >> c >> n >> a;
  vi A(a);
  Q.resize(n);
  for (int i = 0; i < a; ++i) cin >> A[i], Q[A[i]].push(i);
  for (int i = 0; i < n; ++i) Q[i].push(INF + i);

  for (int i = 0; i < a; cache_update(++i)) {
    int ele = A[i];
    if (cache.count(ele)) continue;
    cache_insert(ele, cache.size() >= c), ++reads;
  }

  printf("%d\n", reads);
  return 0;
}
