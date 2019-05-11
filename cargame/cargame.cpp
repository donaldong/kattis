#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;

int solve(v2i &F, v2i &L, v3i &_C, string &s) {
  for (int i = 0; i < F.size(); ++i) {
    int a = s[0] - 'A', m = s[1] - 'A', b = s[2] - 'A';
    int first = F[i][a], last = L[i][b];
#ifdef DEBUG
    printf("first: %d, last: %d\n", first, last);
#endif
    auto &C = _C[i][m];
    if (first < 0 || last < 0 || C.empty()) continue;
    auto left = upper_bound(C.begin(), C.end(), first);
    auto right = --lower_bound(C.begin(), C.end(), last);
    if (left <= right) return i;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  string s;
  v2i F(n, vi(26, -1)), L = F;
  v3i C(n, v2i(26));
  for (int i = 0; i < n; ++i) {
    cin >> s;
    S[i] = s;
    for (int j = 0; j < s.size(); ++j) {
      int a = s[j] - 'a';
      if (F[i][a] < 0) F[i][a] = j;
      L[i][a] = j;
      C[i][a].push_back(j);
    }
  }
  while (m--) {
    cin >> s;
    int i = solve(F, L, C, s);
    printf("%s\n", i < 0 ? "No valid word" : S[i].c_str());
  }
  return 0;
}
