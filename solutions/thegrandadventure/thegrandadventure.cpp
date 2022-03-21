#include <bits/stdc++.h>
using namespace std;

bool solve(string &S) {
  vector<int> V;
  for (char c : S) {
    int v;
    switch (c) {
      case '|': V.push_back(0); break;
      case '*': V.push_back(1); break;
      case '$': V.push_back(2); break;
      case 't': v = 0; break;
      case 'j': v = 1; break;
      case 'b': v = 2; break;
    }
    switch (c) {
      case 't':
      case 'j':
      case 'b':
      if (V.empty() || V.back() != v) return false; V.pop_back();
      break;
    }
  }
  return V.empty();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    printf("%s\n", solve(s) ? "YES" : "NO");
  }
  return 0;
}
