#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N,T,K;
  cin >> N >> T >> K;
  vector<int> freq(T, 0);
  for (int i = 0, v; i < N; ++i) {
    cin >> v; --v;
    ++freq[v];
  }
  using Pair = pair<long long, long long>;
  vector<Pair> P;
  P.reserve(T);
  for (int i = 0, b, s; i < T; ++i) {
    cin >> b >> s;
    P.emplace_back((long long)(2LL-freq[i])*b, (long long)freq[i]*s);
  }
  sort(P.begin(), P.end(), [&](const Pair& a, const Pair& b) {
    return a.first+a.second<b.first+b.second;
  });
  long long res = 0;
  for (int i = 0; i < K; ++i) res -= P[i].first;
  for (int i = K; i < T; ++i) res += P[i].second;
  cout << res << endl;
  return 0;
}
