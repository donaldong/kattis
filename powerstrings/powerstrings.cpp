#include <bits/stdc++.h>
using namespace std;

string line;

bool solve(int k) {
  string tok = line.substr(0, k);
  int i = 0;
  while (i + k < line.size()) {
    i += k;
    if (line.substr(i, k) != tok) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  while (getline(cin, line)) {
    if (line == ".") break;
    int res = 1, k;
    for (int i = 1; i <= line.size(); ++i) {
      if (line.size() % i) continue;
      if (solve(i)) {
        res = line.size() / i;
        break;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
