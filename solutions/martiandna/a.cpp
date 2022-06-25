/**
 * @date        2022-06-24
 * @tags        binary search, moving windows
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,K,R;
  cin >> N >> K >> R;
  vector<int> dna(N);
  using Freq = unordered_map<int,int>;
  Freq req;
  for (int& i : dna) cin >> i;
  for (int i = 0, b, q; i < R; ++i) {
    cin >> b >> q;
    req[b] = q;
  }

  auto incr = [&](Freq& freq, int k, int& cnt) {
    ++freq[k];
    if (req.count(k) && freq[k] == req[k]) ++cnt;
  };

  auto decr = [&](Freq& freq, int k, int& cnt) {
    if (req.count(k) && freq[k] == req[k]) --cnt;
    --freq[k];
  };

  auto possible = [&](int len) {
    Freq freq;
    int cnt = 0;

    for (int i = 0; i < len; ++i) incr(freq, dna[i], cnt);
    if (cnt == req.size()) return true;

    for (int i = len; i < N; ++i) {
      decr(freq, dna[i-len], cnt);
      incr(freq, dna[i], cnt);
      if (cnt == req.size()) return true;
    }

    return false;
  };

  int lo = 0, hi = N;
  while (lo <= hi) {
    int mid = (lo+hi)/2;
    if (possible(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
#ifdef DEBUG
  cerr << lo << ' ' << hi << endl;
#endif
  if (lo-1 >= N) cout << "impossible" << endl;
  else cout << (hi+1) << endl;
  return 0;
}
