#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s;
  int N, k = INT_MAX;
  vector<int> V(4, 0);
  cin >> N;
  while (N--) {
    cin >> s;
    for (int i = 0; i < 4; ++i) if (s[i] == '0') ++V[i];
  }
  k = min(k, (V[0] + V[1]) / 2);
  k = min(k, (V[2] + V[3]) / 2);
  printf("%d %d %d\n", k, V[0] + V[1] - 2 * k, V[2] + V[3] - 2 * k);
  return 0;
}
