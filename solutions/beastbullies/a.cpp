/**
 * @date        2023-02-05
 * @tags        greedy
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> S(n);
  for (int& s : S) cin >> s;
  sort(S.begin(), S.end());
  int a = 1, d = 0;
  ll sa = S.back(), sd = 0;
  for (int i = n-2; i >= 0; --i) {
    sd += S[i], ++d;
    if (sd >= sa) {
      sa += sd;
      a += d;
      sd = 0, d = 0;
    }
  }
  cout << a << endl;
  return 0;
}
