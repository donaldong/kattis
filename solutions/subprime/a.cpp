#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<bool> P(2e6, true);
  P[0] = P[1] = false;
  vector<int> primes;
  primes.reserve(P.size());
  for (int i = 2; i < P.size(); ++i) {
    if (!P[i]) continue;
    primes.push_back(i);
    for (auto j = (long long)i*i; j < P.size(); j += i) P[j] = false;
  }
#ifdef DEBUG
  cout << primes.size() << endl;
#endif
  int l, h;
  cin >> l >> h;
  int res = 0;
  string p;
  cin >> p;
  --l, --h;
  for (int i = l; i < P.size() && i <= h; ++i) {
    if (to_string(primes[i]).find(p) != string::npos) ++res;
  }
  cout << res << endl;
  return 0;
}
