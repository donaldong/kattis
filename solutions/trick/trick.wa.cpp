#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<uint> vi;

ll INF = 1e8;

bool possible(const string &A, const string &B) {
  if (A.size() != B.size() || A[0] != B.back()) return false;
  for (size_t i = 1; i < A.size(); ++i) {
    if (A[i] != B[i - 1]) return false;
  }
  return true;
}

bool possible(ll s, ll n) {
  return possible(to_string(s), to_string(n));
}

bool solve(ll tot, int d) {
  bool f = false;
  ll b, k = 1;
  for (int i = 0; i < d; ++i) k *= 10;
  b = 10 * k - tot;
  ll a = 1;
  for (int i = 0; i <= 7; ++i) {
    a *= 10;
    for (int j = 1; j <= 9; ++j) {
      ll p = (a - 1) * j * k;
#ifdef DEBUG
      cout << p << endl;
#endif
      if (!b || p % b) continue;
      p /= b;
      if (p >= INF) continue;
#ifdef DEBUG
      printf("%lld, n: %d, dig: %d, a: %lld\n", p, i, j, a);
#endif
      ll q = p * tot;
      if (q % k || !possible(p, q / k)) continue;
      printf("%lld\n", p);
      f = true;
    }
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  uint n = 0;
  size_t k = s.find('.');
  if (k != string::npos) while (s.back() == '0') s.pop_back();
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') continue;
    n = 10 * n + s[i] - '0';
  }
  if (!solve(n, s.size() - k - 1)) printf("No solution\n");
  return 0;
}
