#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> tup;
typedef vector<tup> vt;

bool weekend(int i) {
  i = (i - 1) % 7;
  return i == 5 || i == 6;
}

bool solve(vt V, int p, bool use_weekends) {
  int b, e;
  multiset<int> S;
  for (int t = 1, i = 0; t <= 100; ++t) {
      for (; i < V.size(); ++i) {
        tie(b, e) = V[i];
        if (b > t) break;
        S.insert(e);
      }
#ifdef DEBUG
      if (!S.empty()) {
        printf("t=%d: ", t);
        for (auto s : S) printf("%d ", s);
        printf("\n");
      }
#endif
      if (!use_weekends && weekend(t)) continue;
      for (int j = 1; !S.empty() && 2 * j <= p; ++j) {
        e = *S.begin();
        S.erase(S.begin());
        if (e < t) return false;
      }
  }
  return S.empty();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, m, p, b, e;
  cin >> T;
  while (T--) {
    cin >> m >> p;
    vt V;
    V.reserve(m);
    while (m--) {
      cin >> b >> e;
      V.emplace_back(b, e);
    }
    sort(V.begin(), V.end());
    if (solve(V, p, 0)) printf("fine\n");
    else if (solve(V, p, 1)) printf("weekend work\n");
    else printf("serious trouble\n");
  }
  return 0;
}
