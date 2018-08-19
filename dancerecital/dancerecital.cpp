#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

int num_of_qcharge(vector<int> &a, vector<int> &b) {
  int res = 0;
  for (int i = 0; i < 26; ++i) res += min(a[i], b[i]);
  return res;
}

int solve(vector<int> &I) {
  int res = 0;
  for (int i = 0; i < I.size() - 1; ++i) {
    int a = I[i], b = I[i + 1];
    res += num_of_qcharge(G[a], G[b]);
  }
  return res;
}

int main() {
  int r;
  cin >> r;
  G = vector<vector<int>>(r, vector<int>(26, 0));
  for (int i = 0; i < r; ++i) {
    string row;
    cin >> row;
    for (char c : row) ++G[i][c - 'A'];
  }
  vector<int> I(r);
  for (int i = 0; i < r; ++i) I[i] = i;
  int res = 1e9;
  do {
    res = min(res, solve(I));
  } while (next_permutation(I.begin(), I.end()));
  cout << res << endl;
  return 0;
}
