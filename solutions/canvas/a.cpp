/**
 * @date        2022-03-26
 * @tags        greedy, data structure
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int T,N;
  cin >> T;
  while (T--) {
    cin >> N;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    while (N--) {
      int v;
      cin >> v;
      pq.push(v);
    }
    long long res = 0;
    while (pq.size() > 1) {
      ll a = pq.top(); pq.pop();
      ll b = pq.top(); pq.pop();
      res += a+b;
      pq.push(a+b);
    }
    cout << res << endl;
  }
  return 0;
}
