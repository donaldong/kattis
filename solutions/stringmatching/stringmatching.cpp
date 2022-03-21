#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  string pattern, text;
  while (
    getline(cin, pattern) &&
    getline(cin, text)
  ) {
    size_t pos = text.find(pattern, 0);
    bool f = true;
    while (pos != -1) {
      if (!f) cout << ' ';
      f = false;
      cout << pos;
      pos = text.find(pattern, pos + 1);
    }
    cout << endl;
  }
  return 0;
}
