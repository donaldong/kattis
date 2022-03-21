#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  size_t p = 0;
  for (int i = 1; i <= n; ++i) {
    auto s2 = to_string(i);
    auto p2 = s.find(s2, p);
    if (p2 != p) {
      cout << s2 << endl;
      break;
    }
    p = p2+s2.size();
  }
  return 0;
}
