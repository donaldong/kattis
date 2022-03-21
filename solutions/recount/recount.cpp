#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string line;
  unordered_map<string, int> C;
  int max_count = 0;
  while (getline(cin, line)) {
    if (line == "***") break;
    ++C[line];
    max_count = max(max_count, C[line]);
  }
  bool f = true;
  string winner;
  for (auto &entry : C) {
    if (entry.second == max_count) {
      if (!f) {
        cout << "Runoff!" << endl;
        return 0;
      }
      f = false;
      winner = entry.first;
    }
  }
  cout << winner << endl;
  return 0;
}
