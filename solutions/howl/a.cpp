#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  bool added = false;
  for (char c : s) {
    cout << c;
    if (!added && c == 'O') {
      cout << 'O';
      added = true;
    }
  }
  cout << endl;
  return 0;
}
