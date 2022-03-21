#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  string s;
  while (n--) {
    cin >> s;
    for (char& c: s) c = tolower(c);
    if (s.find("pink") != string::npos || s.find("rose") != string::npos) ++cnt;
  }
  if (!cnt) cout << "I must watch Star Wars with my daughter" << endl;
  else cout << cnt << endl;
  return 0;
}
