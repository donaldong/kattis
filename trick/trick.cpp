#include <bits/stdc++.h>
using namespace std;

typedef vector<uint> vi;
uint MAX_NUM = 1e7;

bool possible(uint s, uint n) {
  string A = to_string(s), B = to_string(n);
  if (A.size() != B.size() || A[0] != B.back()) return false;
  for (size_t i = 1; i < A.size(); ++i) {
    if (A[i] != B[i - 1]) return false;
  }
  return true;
}

bool solve(uint n, uint last_dig) {
  vi opts = {0};
#ifdef DEBUG
  printf("%u %u\n", n, last_dig);
#endif
  for (int i = 2; i <= 8; ++i) {
    if ((last_dig * i) % 10 == 0) {
#ifdef DEBUG
      printf("opt: %d %u\n", i, last_dig * i / 10);
#endif
      opts.push_back(i);
    }
  }
  bool f = false;
  for (uint i = 0; i < MAX_NUM; ++i) {
    for (auto d : opts) {
      uint s = 10 * i + d;
      if (!s) continue;
      uint res = last_dig * s / 10 + n * s;
      if (possible(s, res)) f = true, printf("%d\n", s);
    }
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  uint n = 0;
  if (s.find('.') != string::npos) while (s.back() == '0') s.pop_back();
  for (int i = 0; i + 1 < s.size(); ++i) {
    if (s[i] == '.') continue;
    n = 10 * n + s[i] - '0';
  }
  uint last_dig = s.back() - '0';
  if (!solve(n, last_dig)) printf("No solution\n");
  return 0;
}
