#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> G(5);
  for (int i = 0; i < 5; ++i) cin >> G[i];
  int v;
  cin >> v;
  string res = "ABCDE";
  for (int i = 0; i < 5; ++i) {
    if (v >= G[i]) {
      cout <<  res[i] << endl;
      return 0;
    }
  }
  cout << "F" << endl;
  return 0;
}
