/**
 * @date        2022-11-04
 * @tags        stack, implementation
 * @difficulty  1200
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, k;
  cin >> n >> k;
  vector<int> commands;
  for (int i = 0; i < k; ++i) {
    string c;
    int v;
    cin >> c;
    if (c[0] == 'u') {
      cin >> v;
      while (v--) commands.pop_back();
    } else {
      v = stoi(c) % n;
      commands.push_back(v<0?v+n:v);
    }
  }
  cout << accumulate(commands.begin(), commands.end(), 0)%n << endl;;
  return 0;
}
