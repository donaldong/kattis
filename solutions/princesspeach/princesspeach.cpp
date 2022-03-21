#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, y, c = 0;
  cin >> n >> y;
  vb V(n, false);
  for (int i = 0; i < y; ++i) {
    cin >> n;
    V[n] = true;
  }
  for (size_t i = 0; i < V.size(); ++i) {
    if (!V[i]) cout << i << endl;
    else ++c;
  }
  printf("Mario got %d of the dangerous obstacles.", c);
  cout << endl;
  return 0;
}
