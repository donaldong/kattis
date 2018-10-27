#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, w;
  cin >> l >> w;
  int left = w - l;
  if (l * 25 < left || left < 0) cout << "impossible";
  else for (int i = 0; i < l; ++i) {
    if (left) {
      int delta = min(25, left);
      cout << char('a' + delta);
      left -= delta;
    } else cout << 'a';
  }
  cout << endl;
  return 0;
}
