/**
 * @date        2022-03-26
 * @tags        grid, math, random
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  pair<int,int> A, B;
  vector<pair<int,int>> moves(N);
  cin >> A.first >> A.second >> B.first >> B.second;
  for (auto& m : moves) cin >> m.first >> m.second;

  auto canWin = [&]() {
    set<pair<int,int>> S;
    int r,c;
    for (auto [dr, dc] : moves) {
      r = A.first+dr, c = A.second+dc;
      if (r <= 0 || r > N || c <= 0 || c > N) continue;
      S.emplace(r, c);
    }
    for (auto [dr, dc] : moves) {
      r = B.first-dr, c = B.second-dc;
      if (r <= 0 || r > N || c <= 0 || c > N) continue;
      if (S.find(make_pair(r,c)) != S.end()) return true;
    }
    return false;
  };

  auto solveSmall = [&]() -> pair<int,int> {
    set<pair<int,int>> S, S2;
    for (auto [dr, dc] : moves) {
      int r = B.first+dr, c = B.second+dc;
      if (r <= 0 || r > N || c <= 0 || c > N) continue;
      S.emplace(r, c);
    }
    for (auto [r, c] : S) {
      for (auto [dr, dc] : moves) {
        int r2 = r+dr, c2 = c+dc;
        if (r2 <= 0 || r2 > N || c2 <= 0 || c2 > N) continue;
        S2.emplace(r2, c2);
      }
    }
    S.emplace(B);
    S.insert(S2.begin(), S2.end());
    for (int r = 1; r <= N; ++r) for (int c = 1; c <= N; ++c) {
      if (S.find(make_pair(r, c)) == S.end()) return {r,c};
    }
    return {-1,-1};
  };

  auto solve = [&]() -> pair<int,int> {
    if (N <= 1000) return solveSmall();
    // the grid is too big to be fully covered. Try some random places
    set<pair<int,int>> S;
    for (auto [dr, dc] : moves) {
      int r = B.first+dr, c = B.second+dc;
      if (r <= 0 || r > N || c <= 0 || c > N) continue;
      S.emplace(r, c);
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, N);
    while (true) {
      int r = dist(gen), c = dist(gen);
      bool valid = true;
      for (auto [dr, dc] : moves) {
        int r2 = r-dr, c2 = c-dc;
        if (r2 <= 0 || r2 > N || c2 <= 0 || c2 > N) continue;
        if (S.find(make_pair(r2,c2)) != S.end()) {
          valid = false;
          break;
        }
      }
      if (valid) return {r, c};
    }
    return {-1,-1};
  };

  if (canWin()) {
    cout << "Alice wins" << endl;
    return 0;
  }
  auto [r, c] = solve();
  if (r <= 0 || c <= 0) cout << "Bob wins" << endl;
  else printf("tie %d %d\n", r, c);
  return 0;
}
