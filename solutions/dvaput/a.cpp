/**
 * NOTE: This is not a working solution (Runtime Error)
 *
 * See https://github.com/e-maxx-eng/e-maxx-eng/issues/815
 */
#include <bits/stdc++.h>

using namespace std;
struct SuffixArray { // https://cp-algorithms.com/string/suffix-array.html
  int n;
  vector < int > p;
  vector < vector < int >> C;
  SuffixArray(const string & s) {
    n = s.size();
    const int alphabet = 1 << 8;
    vector < int > cnt(max(alphabet, n), 0), c(n);
    p.resize(n);
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
      if (s[p[i]] != s[p[i - 1]]) classes++;
      c[p[i]] = classes - 1;
    }
    vector < int > pn(n);
    for (int h = 0;
      (1 << h) < n; ++h) {
      vector < int > cn(n);
      for (int i = 0; i < n; i++) {
        pn[i] = p[i] - (1 << h);
        if (pn[i] < 0) pn[i] += n;
      }
      fill(cnt.begin(), cnt.begin() + classes, 0);
      for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
      for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
      for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0;
      classes = 1;
      for (int i = 1; i < n; i++) {
        pair < int, int > cur = {
          c[p[i]],
          c[(p[i] + (1 << h)) % n]
        };
        pair < int, int > prev = {
          c[p[i - 1]],
          c[(p[i - 1] + (1 << h)) % n]
        };
        if (cur != prev)
          ++classes;
        cn[p[i]] = classes - 1;
      }
      C.push_back(move(c));
      c = move(cn);
    }
    C.push_back(move(c));
  }
  int lcp(int i, int j) {
    int ans = 0, l = i, r = j;
    for (int k = C.size() - 1; k >= 0; k--) { // missing boundary check for i and j
      int b = 1 << k;
      if (C[k][i] == C[k][j]) {
        ans += b;
        i += b;
        j += b;
      }
    }
    return min({
      ans,
      n - l,
      n - r
    });
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int L;
  string s;
  cin >> L >> s;
  SuffixArray sa(s);
  int res = 0;
  for (int i = 1; i < L; ++i) {
    res = max(res, sa.lcp(sa.p[i - 1], sa.p[i]));
  }
  cout << res << endl;
  return 0;
}
