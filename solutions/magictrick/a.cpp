#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  unordered_set<char> S;
  for (char c : s) {
    if (S.count(c)) {
      cout << 0 << endl;
      return 0;
    }
    S.insert(c);
  }
  cout << 1 << endl;
  return 0;
}
