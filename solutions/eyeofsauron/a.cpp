#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int l = 0, r = s.size()-1;
  while (l < r) {
    if (l >= r) break;
    if (l+1 == r) {
      if (s[l] == '('  && s[r] == ')') {
        cout << "correct" << endl;
        return 0;
      }
      break;
    }
    if (s[l] != '|' || s[r] != '|') break;
    ++l, --r;
  }
  cout << "fix" << endl;
  return 0;
}
