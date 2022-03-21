#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  while (s.size() > 1) {
    long long p = 1;
    for (char c : s) {
      if (c == '0') continue;
      p *= c-'0';
    }
    s = to_string(p);
  }
  cout << s << endl;
  return 0;
}
