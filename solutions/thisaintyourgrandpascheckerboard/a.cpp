#include <bits/stdc++.h>
using namespace std;
bool valid(vector<string>& G) {
  for (auto& row : G) {
    unordered_map<char,int> freq;
    for (int i = 0; i < row.size(); ++i) {
      if (i >= 2 && row[i] == row[i-1] && row[i] == row[i-2]) return false;
      ++freq[row[i]];
    }
    if (freq['W'] != freq['B']) return false;
  }
  for (int c = 0; c < G[0].size(); ++c) {
    unordered_map<char,int> freq;
    for (int r = 0; r < G.size(); ++r) {
      if (r >= 2 && G[r][c] == G[r-1][c] && G[r][c] == G[r-2][c]) return false;
      ++freq[G[r][c]];
    }
    if (freq['W'] != freq['B']) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int r;
  cin >> r;
  vector<string> G(r);
  for (auto& row : G) cin >> row;
  cout << valid(G) << endl;
  return 0;
}
