#include <bits/stdc++.h>
using namespace std;

struct score {
  int s, p, f, o, i;
  int tot;
  bool operator==(const score &b) const {
    return s == b.s && p == b.p && f == b.f;
  }
};

typedef vector<score> vs;
typedef vector<int> vi;

int main() {
  int n, s, c = 0, avg;
  scanf("%d", &n);
  vs scores(n);
  vi S(n, 0);
  S[0] = 100, S[1] = 75, S[2] = 60, S[3] = 50;
  S[4] = 45, S[5] = 40, S[6] = 36, S[7] = 32;
  S[8] = 29, S[9] = 26, S[10] = 24, S[11] = 22;
  S[12] = 20, S[13] = 18;
  for (int i = 0; i < 16; ++i) S[14 + i] = 16 - i;
  for (int i = 0; i < n; ++i) {
    scanf(
      "%d %d %d %d",
      &scores[i].s, &scores[i].p, &scores[i].f, &scores[i].o
    );
    scores[i].i = i;
  }
  sort(scores.begin(), scores.end(), [](const score &a, const score &b) {
    if (a.s != b.s) return a.s > b.s;
    if (a.p != b.p) return a.p < b.p;
    return a.f < b.f;
  });
  for (int i = 0; i < n;) {
    s = S[i], c = 1;
    while (i + 1 < n && scores[i] == scores[i + 1]) ++c, ++i, s += S[i];
    avg = s / c;
    if (s % c) ++avg;
    for (int j = 0; j < c; ++j) {
      scores[i - j].tot = avg + scores[i - j].o;
    }
    ++i;
  }
  sort(scores.begin(), scores.end(), [](const score &a, const score &b) {
    return a.i < b.i;
  });
  for (int i = 0; i < n; ++i) printf("%d\n", scores[i].tot);
  return 0;
}
