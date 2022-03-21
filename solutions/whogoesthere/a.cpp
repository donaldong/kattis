#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> M(m), res(m, 0);
  for (int& v : M) cin >> v;
  queue<int> q;
  for (int i = 0; i < m; ++i) q.push(i);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    if (M[i]) --M[i], ++res[i], --n;
    if (M[i]) q.push(i);
    if (!n) break;
  }
  for (int r : res) cout << r << endl;
  return 0;
}
