#include <bits/stdc++.h>
using namespace std;
vector<string> toks{":)", ";)", ":-)", ";-)"};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  size_t pos = 0;
  while (pos != string::npos) {
    size_t pos2 = string::npos;
    int k = -1;
    for (int i = 0; i < toks.size(); ++i) {
      auto p = s.find(toks[i], pos);
      if (p == string::npos) continue;
      p += toks[i].size();
      if (p >= pos2) continue;
      pos2 = p, k = i;
    }
    if (k>=0) cout << pos2-toks[k].size()<< endl;
    pos = pos2;
  }
  return 0;
}
