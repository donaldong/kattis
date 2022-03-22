/**
 * @author      Donald Dong
 * @date        2022-03-21
 * @tags        hash map
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0); // Fast IO
  int n, m;
  cin >> n;
  string s1, s2;
  getline(cin, s1);
  unordered_map<string, string> P;
  while (n--) {
    getline(cin, s1);
    getline(cin, s2);
    P[s1] = move(s2);
  }
  cin >> m;
  getline(cin, s1);
  unordered_map<string, int> C;
  int maxCnt = 0, freq = 0;
  string winner;
  while (m--) {
    getline(cin, s1);
    auto& c = C[s1];
    maxCnt = max(maxCnt, ++c);
  }

  for (const auto& [name, k] : C) {
    if (k == maxCnt) ++freq, winner = name;
  }
  if (freq != 1) cout << "tie" << endl;
  else cout << P[winner] << endl;
}
