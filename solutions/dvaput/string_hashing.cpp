/**
 * @date        2022-03-22
 * @tags        string, string hashing
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
using Hash = __int128;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int L;
  string s;
  cin >> L >> s;

  auto possible = [&](int len) {
    unordered_map<Hash, int> P;
    /*
      since the string is pretty long, we need a big base to avoid collision;
      m=1e9+9 is not good enough (WA)
    */
    const Hash p = 31;
    const Hash m = 984162944621615797;
    vector<Hash> p_pow(s.size());
    p_pow[0] = 1;
    for (int i = 1; i < s.size(); i++) p_pow[i] = (p_pow[i-1] * p) % m;

    vector<Hash> h(s.size()+1, 0);
    for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    for (int i = 0; i <= s.size()-len; ++i) {
      long long cur_h = (h[i+len] + m - h[i]) % m;
      cur_h = (cur_h * p_pow[s.size()-i-1]) % m;
      auto cnt = ++P[cur_h];
      if (cnt>=2) return true;
    }
    return false;
  };

  int l = 1, r = s.size();
  while (l<=r) {
    int mid = (l+r)/2;
    if (possible(mid)) l=mid+1;
    else r = mid-1;
  }
  cout << l-1 << endl;

  return 0;
}
