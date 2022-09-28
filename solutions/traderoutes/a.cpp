/**
 * @date        2022-09-27
 * @tags        graph, greedy
 * @difficulty  1900
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  vector<int> B(n), V(n);
  for (int i = 1, j; i < n; ++i) {
    cin >> j;
    tree[--j].push_back(i);
  }
  for (auto& b : B) cin >> b;
  for (auto& v : V) cin >> v;

  auto compare = [&](int a, int b) {
    return V[a] > V[b];
  };
  using pqueue = priority_queue<int, vector<int>, decltype(compare)>;
  using pq_ptr = unique_ptr<pqueue>;

  // greedily maintain b_i most valuable cities at city i O(n*logn*logn)
  function<pq_ptr(int, pq_ptr)> dfs = [&](int u, pq_ptr pq) {
    pq->push(u);
    for (int v : tree[u]) {
      auto pq2 = dfs(v, make_unique<pqueue>(compare));
      if (pq2->size() > pq->size()) {
        // important! We only want to merge the smaller heap into bigger heap
        // so we can move each number at most O(logn) times
        swap(pq, pq2); 
      }
      while (!pq2->empty()) {
        pq->push(pq2->top());
        pq2->pop();
      }
    }
    while (pq->size() > B[u]) pq->pop();
    return pq;
  };

  auto pq = dfs(0, make_unique<pqueue>(compare));
  ll max_val = 0;
  vector<int> cities; // print outputs
  cities.reserve(pq->size());
  while (!pq->empty()) {
    auto c = pq->top();
    pq->pop();
    cities.push_back(c);
    max_val += V[c];
  }
  sort(cities.begin(), cities.end());
  cout << max_val << '\n' << cities.size() << ' ';
  for (auto c : cities) cout << c+1 << ' ';
  cout << endl;
  return 0;
}
