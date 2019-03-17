#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
vll N;

ll solve(int mask) {
  vll S = {N[0]};
  for (int i = 1; i < N.size(); ++i) {
    if (mask & 1) S.push_back(N[i]);
    else {
      string s = to_string(S.back()) + to_string(N[i]);
      S.back() = stoll(s);
    }
    mask >>= 1;
  }
  ll res = 0;
  for (ll s : S) res += s;
#ifdef DEBUG
  printf("res: %lld\n", res);
#endif
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  string tok;
  while (getline(cin, tok, '+')) {
#ifdef DEBUG
  printf("+%s\n", tok.c_str());
#endif
    N.push_back(stoll(tok));
  }
  int t = 1 << (N.size() - 1);
  unordered_set<ll> S;
  for (int i = 0; i < t; ++i) {
    S.insert(solve(i));
  }
  printf("%zu\n", S.size());
  return 0;
}
