#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;

char H(string &s) {
  char c = s[0];
  for (size_t i = 1; i < s.size(); ++i) {
    c ^= s[i];
  }
  return c;
}

int main() {
  string line;
  int n;
  while (getline(cin, line)) {
    if (line == "0") break;
    int n = stoi(line);
    unordered_set<string> S;
    vs F(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, F[i]);
      S.insert(F[i]);
    }
    int collision = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (F[i] == F[j]) continue;
        if (H(F[i]) == H(F[j])) ++collision;
      }
    }
    cout << S.size() << " " << collision << endl;
  }
  return 0;
}
