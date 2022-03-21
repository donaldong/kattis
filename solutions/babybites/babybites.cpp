#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string word;
  int count = 1, k;
  bool f = true;
  while (n--) {
    cin >> word;
    if (word[0] == 'm') ++count;
    else {
      k = stoi(word);
      if (k != count) {
        f = false; break;
      }
      ++count;
    }
  }
  cout << (f ? "makes sense" : "something is fishy") << endl;
  return 0;
}
