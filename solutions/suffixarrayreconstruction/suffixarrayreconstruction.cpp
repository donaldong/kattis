#include <bits/stdc++.h>
using namespace std;

bool update(string &S, int p, string &s) {
  for (int i = 0; i < s.size(); ++i) {
    int j = i + p; 
    if (j >= S.size()) return false;
    if (!S[j] || S[j] == '*') S[j] = s[i];
    else if (S[j] != s[i] && s[i] != '*') return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int l, s;
    cin >> l >> s;
    string S(l, 0);
    bool possible = true;
    while (s--) {
      string a;
      int p;
      cin >> p >> a;
      --p;
      if (possible) {
        if (!update(S, p, a)) possible = false;
      }
    }
    for (char c : S) if (!c) {
      possible = false;
      break;
    }
    if (!possible) cout << "IMPOSSIBLE" << endl;
    else cout << S << endl;
  }
  return 0;
}
