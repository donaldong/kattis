/**
 * @date        2022-03-25
 * @tags        moving window, binary search
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int K, N;
  cin >> K;
  vector<int> res;
  for (int i = 1, h; i <= K; ++i) {
    cin >> N;
    vector<int> H(N), R(N, 0);
    bool possible = false;
    for (int& h : H) cin >> h;
    R.back() = H.back();
    for (int i = N-2; i >=0; --i) R[i] = max(R[i+1], H[i]);
    set<int> L;
    L.insert(H[0]);
    for (int i = 1; i <= N-2; ++i) {
      auto h = H[i];
      auto r = R[i+1];
      auto itr = L.upper_bound(h);
      if (itr != L.end() && *itr<r) possible = true;
      L.insert(h);
    }

    if (possible) res.push_back(i);
  }
  cout << res.size() << endl;
  for (int i : res) cout << i << endl;
  return 0;
}
