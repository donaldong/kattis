#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map


int N;
// Transitive Matrix
vector<vector<bool>> M;
// Speak / Understand Languages
hmap<string, vector<int>> S, U;

void build() {
  for (auto &entry : S) {
    for (size_t i = 0; i < entry.second.size(); ++i) {
      for (size_t j = i + 1; j < entry.second.size(); ++j) {
        int a = entry.second[i];
        int b = entry.second[j];
        M[a][b] = true;
        M[b][a] = true;
      }
    }
  }
  for (auto &entry : U) {
    auto speakers = S[entry.first];
    for (int i : entry.second) {
      for (int j : speakers) {
        M[j][i] = true;
      }
    }
  }
}

void debug_solve() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int solve() {
  // Transitive closure
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (M[i][k] && M[k][j]) M[i][j] = true;
      }
    }
  }
  // Closed index
  vector<int> C;
  for (int i = 0; i < N; ++i) {
    if (M[i][i]) C.push_back(i);
  }
  // Freq
  vector<int> F(N, 0);
  for (int i : C) {
    for (int j : C) {
      if (M[j][i] && M[i][j]) ++F[i];
    }
  }
  int res = 0;
  for (int f : F) res = max(res, f);
  return N - res;
}

int main() {
  string line;
  getline(cin, line);
  N = stoi(line);
  M = vector<vector<bool>>(N, vector<bool>(N, false));
  for (int i = 0; i < N; ++i) {
    getline(cin, line);
    stringstream ss(line);
    string s;
    ss >> s >> s;
    S[s].push_back(i);
    while (ss >> s) {
      U[s].push_back(i);
    }
  }
  build();
  cout << solve() << endl;
  return 0;
}
