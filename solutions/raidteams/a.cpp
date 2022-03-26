/**
 * @date        2022-03-25
 * @tags        sorting, implementation
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector<bool> vis(N, false);
  vector<int> head(3, 0);
  vector<string> names(N);
  vector<vector<int>> S(3, vector<int>(N));
  vector<vector<int>> R(3, vector<int>(N));
  for (int i = 0; i < N; ++i) R[0][i] = R[1][i] = R[2][i] = i;
  for (int i = 0, a,b,c; i < N; ++i) {
    cin >> names[i];
    for (int j = 0; j < 3; ++j) cin >> S[j][i];
  }
  for (int i = 0; i < 3; ++i) {
    sort(R[i].begin(), R[i].end(), [&](int a, int b) {
      if (S[i][a] == S[i][b]) return names[a]<names[b];
      return S[i][a]>S[i][b];
    });
  }
  for (int i = 0; i+3 <= N;) {
    vector<string> res(3);
    for (int j = 0; j < 3; ++j, ++i) {
      while (head[j]<N && vis[R[j][head[j]]]) ++head[j];
      int k = R[j][head[j]];
      res[j] = move(names[k]);
      vis[k] = true;
      ++head[j];
    }
    sort(res.begin(), res.end());
    for (auto& s : res) cout << s << ' ';
    cout << endl;
  }
  return 0;
}
