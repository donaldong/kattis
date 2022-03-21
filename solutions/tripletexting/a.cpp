#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size()/3; ++i) {
    unordered_map<char, int> freq;
    char c;
    int f = 0;
    for (int j = 0; j < 3; ++j) {
      int p = i+s.size()/3*j;
      ++freq[s[p]];
      if (freq[s[p]]>f) f = freq[s[p]], c = s[p];
    }
    cout << c;
  }
  cout << endl;
  return 0;
}
