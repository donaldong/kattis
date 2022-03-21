#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s, k;
  cin >> s >> k;
  for (int i = 0; i < s.size(); ++i) {
    int d = k[i]-'A';
    int t = s[i]-'A';
    if (i%2) t += d;
    else t -= d;
    s[i] = (t+26)%26+'A';
  }
  cout << s << endl;
  return 0;
}
