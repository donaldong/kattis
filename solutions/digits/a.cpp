#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    if (s[0] == 'E') break;
    int x1 = s.size(), i = 1;
    while (true) {
      auto s2 = to_string(x1);
      if (s2 == s) {
        cout << i << endl;
        break;
      }
      x1 = s2.size();
      swap(s, s2);
      ++i;
    }
  }
  return 0;
}
