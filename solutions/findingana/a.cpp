#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  auto p = s.find('a');
  cout << s.substr(p) << endl;
  return 0;
}
