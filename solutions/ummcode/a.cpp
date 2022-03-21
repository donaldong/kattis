#include <bits/stdc++.h>
using namespace std;

bool valid(string &s) {
  for (char c : s) {
    bool letterOrDigit = tolower(c)>='a'&&tolower(c)<='z';
    letterOrDigit = letterOrDigit || (c>='0'&&c<='9');
    if (letterOrDigit && c != 'u' && c != 'm') return false;
  }
  return true;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s, tok;
  while (cin >> tok) {
    if (!valid(tok)) continue;
    for (char c : tok) if (c == 'u' || c == 'm') s += c;
  }
  for (int i = 0; i < s.size();) {
    int val = 0;
    for (int j = 0; j < 7; ++j,++i) {
      char c = s[i];
      val <<= 1;
      if (c == 'u') ++val;
    }
    cout<<(char)val;
  }
  cout << endl;
  return 0;
}
