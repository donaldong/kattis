#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi parse(const string &s) {
  vi res(26, 0);
  int a = s[0] - 'A';
  int cur = 0;
#ifdef DEBUG
  printf("%s\n", s.c_str());
#endif
  for (size_t i = 1; i < s.size(); ++i) {
    if ('A' <= s[i] && s[i] <= 'Z') {
#ifdef DEBUG
      printf("[%c] += %d\n", a + 'A', max(cur, 1));
#endif
      res[a] += max(cur, 1);
      a = s[i] - 'A';
      cur = 0;
    } else {
      cur = 10 * cur + s[i] - '0';
    }
  }
#ifdef DEBUG
      printf("[%c] += %d\n", a + 'A', max(cur, 1));
#endif
  res[a] += max(cur, 1);
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string a, b;

  cin >> a >> n >> b;
  vi A = parse(a), B = parse(b);

  int res = 1e9;
  for (int i = 0; i < 26; ++i) {
    if (!B[i]) continue;
#ifdef DEBUG
    printf("A has %d x %c, B needs %d\n", A[i] * n, i + 'A', B[i]);
#endif
    res = min(res, A[i] * n / B[i]);
  }
  printf("%d\n", res);
  return 0;
}
