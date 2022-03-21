#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long inv = 0, mod = 1e9+7, zeros = 0, seqs = 1;
  for (int i = s.size()-1; i>=0; --i) {
    char c = s[i];
    if (c == '1' || c == '?') {
      if (c == '?') inv += inv;
      inv += zeros;
      inv %= mod;
    }
    if (c == '0') {
      zeros += seqs;
      zeros %= mod;
    }
    if (c == '?') {
      zeros <<= 1;
      zeros += seqs;
      zeros %= mod;
      seqs <<= 1;
      seqs %= mod;
    }
#ifdef DEBUG
    printf("inv=%lld\tzeros=%lld\tseqs=%lld\n", inv, zeros, seqs);
#endif
  }
  cout << inv << endl;
  return 0;
}
