/**
 * @date        2022-03-27
 * @tags        data structure, bit mask
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,M;
  cin >> N >> M;
  vector<bitset<1001>> B(N);
  for (int i = 0, k, n; i < N; ++i) {
    cin >> k;
    while (k--) {
      cin >> n;
      B[i].set(n);
    }
  }
  vector<int> notes(M);
  for (int& note : notes) cin >> note;
  int i = 0, res = 0;
  bitset<1001> S;
  while (i < M) {
    S.set(notes[i]);
    bool valid = false;
    for (auto& s : B) {
      if ((s&S).count() == S.count()) {
        valid = true;
        break;
      }
    }
    if (!valid) {
      ++res;
      S.reset();
      S.set(notes[i]);
    }
    ++i;
  }
  cout << res << endl;
  return 0;
}
