#include <bits/stdc++.h>
using namespace std;
bool accepted(string& s, string& p) {
  if (s == p) return true;
  if (s[0] >= '0' && s[0] <= '9' && s.size()==p.size()+1 && s.substr(1) == p) return true;
  if (s.back() >= '0' && s.back() <= '9' && s.size()==p.size()+1 && s.substr(0,s.size()-1) == p) return true;
  for (char& c : p) {
    if (c >= 'a' && c <= 'z') c = toupper(c);
    else if (c >= 'A' && c <= 'Z') c = tolower(c);
  }
  return s == p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s, p;
  cin >> s >> p;
  cout << (accepted(s,p)?"Yes":"No") << endl;
  return 0;
}
