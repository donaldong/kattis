/**
 * @date        2022-04-01
 * @tags        greedy
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Tuple = tuple<ll,int>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int h,c,a,d;
  ll res=0;
  priority_queue<Tuple,vector<Tuple>,greater<Tuple>> pq;
  cin >> h >> c;
  while (c--) {
    cin >> a >> d;
    res = max(res, (ll)a);
    pq.emplace(a+d, d);
  }
  for (; h && !pq.empty(); --h) {
    auto [a, d] = pq.top(); pq.pop();
    res = max(res, a);
    pq.emplace(a+d,d);
  }
  cout << res << endl;
  return 0;
}
