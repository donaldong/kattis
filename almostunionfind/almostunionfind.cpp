#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
vector<int> P, R;
vector<ll> S;

int find(int n) {
  if (P[n] == n) return n;
  return P[n] = find(P[n]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int m, c, p, q, a, b;
  while (cin >> N >> m) {
    ++N;
    P.resize(2 * N), R.resize(P.size()), S.resize(P.size());
    for (int i = 1, j = i + N; i < N; ++i, ++j) {
      P[i] = P[j] = j, R[j] = 1, S[j] = i;
      R[i] = S[i] = 0;
    }
    while (m--) {
      cin >> c >> p;
      if (c == 1) {
        cin >> q;
        a = find(p), b = find(q);
        if (a != b) { // join
          R[a] += R[b], R[b] = 0;
          S[a] += S[b], S[b] = 0;
          P[b] = a;
        }
      } else if (c == 2) {
        cin >> q;
        a = find(p), b = find(q);
        if (a != b) { // move
          S[a] -= p, --R[a];
          S[b] += p, ++R[b];
          R[p] = 0, S[p] = 0, P[p] = b;
        }
      } else {
        a = find(p);
        printf("%d %lld\n", R[a], S[a]);
      }
    }
  }
  return 0;
}
