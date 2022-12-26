/**
 * @date        2022-11-12
 * @tags        greedy, heap, priority queue
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, k;
  cin >> n >> k;
  unordered_map<int,int> F;
  priority_queue<int> pq;
  for (int i = 0, v; i < n; ++i) {
    cin >> v;
    ++F[v];
  }
  for (auto [v, f] : F) pq.emplace(f);
  for (int i = 0; i < k; ++i) {
    auto f = pq.top();
    pq.pop();
    pq.emplace(f-1);
  }
  if (pq.empty()) cout << 0 << endl;
  else cout << pq.top() << endl;
  return 0;
}
