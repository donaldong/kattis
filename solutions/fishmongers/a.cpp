/**
 * @date        2022-03-27
 * @tags        greedy
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,M;
  cin >> N >> M;
  vector<int> F(N);
  for (int& f : F) cin >> f;
  vector<pair<int,int>> B(M);
  for (auto& b : B) {
    cin >> b.second >> b.first;
  }
  sort(F.rbegin(), F.rend());
  sort(B.rbegin(), B.rend());
  long long res = 0;
  for (int i = 0, j = 0; i < F.size() && j < B.size(); ++j) {
    long long kilos = 0;
    while (B[j].second-- && i < F.size()) kilos += F[i++];
    res += kilos * B[j].first;
  }
  cout << res << endl;
  return 0;
}
