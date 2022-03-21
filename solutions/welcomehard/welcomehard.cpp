#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

unordered_map<char, int> ID = {
  {' ', 0}, {'a', 1}, {'c', 2},
  {'d', 3}, {'e', 4}, {'j', 5},
  {'l', 6}, {'m', 7}, {'o', 8},
  {'t', 9}, {'w', 10}
};
v2i DP, G;
string MSG = "welcome to code jam";
int MOD = 1e4;

int solve(int i, int j) {
  if (i == MSG.size()) return 1;
  if (DP[i][j] >= 0) return DP[i][j];
  int res = 0;
  for (int k : G[ID[MSG[i]]]) if (k >= j) {
    res = (res + solve(i + 1, k)) % MOD;
  }
  DP[i][j] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  int t = 1;
  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    G.assign(11, vi()), DP.assign(19, vi(500, -1));
    for (int i = 0; i < line.size(); ++i) {
      if (ID.find(line[i]) == ID.end()) continue;
      G[ID[line[i]]].push_back(i);
    }
    printf("Case #%d: %04d\n", t++, solve(0, 0));
  }
  return 0;
}
