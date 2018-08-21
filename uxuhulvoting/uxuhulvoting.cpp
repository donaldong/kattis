#include <bits/stdc++.h>
using namespace std;

#define hset unordered_set

int M;
// States, Grid
vector<vector<int>> S, G;

int best(vector<int> &P, hset<int> &states) {
  vector<tuple<int, int>> A(8);
  for (int i = 0; i < 8; ++i) {
    A[i] = make_tuple(P[i], i);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < 8; ++i) {
    int p, k;
    tie(p, k) = A[i];
    if (states.find(k) != states.end()) return k;
  }
  return 0;
}

int solve(int i, int state) {
  if (S[i][state] != -1) return S[i][state];
  int res;
  hset<int> states;
  for (int k = 0; k < 3; ++k) {
    int s2 = state;
    s2 ^= (1 << k);
    if (i + 1 == M) states.insert(s2);
    else states.insert(solve(i + 1, s2));
  }
  res = best(G[i], states);
  S[i][state] = res;
  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> M;
    G = vector<vector<int>>(M, vector<int>(8, - 1));
    S = G;
    for (auto &row : G) {
      for (auto &i : row) cin >> i;
    }
    int res = solve(0, 0);
    string output;
    for (int i = 0; i < 3; ++i) {
      if (res & 1) output = 'Y' + output;
      else output = 'N' + output;
      res >>= 1;
    }
    cout << output << endl;
  }
  return 0;
}
