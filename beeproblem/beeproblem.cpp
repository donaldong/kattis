#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int N, M;
int DR[] = {-1, -1, 0, 1, 1, 0};
int DC[] = {-1, 1, 2, 1, -1, -2};
vector<string> G;
vi C;

int fill(int r, int c) {
  int r2, c2, res = 1;
  G[r][c] = '#';
  queue<tuple<int, int>> Q;
  Q.emplace(r, c);
  while (!Q.empty()) {
    tie(r, c) = Q.front(), Q.pop();
    for (int d = 0; d < 6; ++d) {
      r2 = r + DR[d], c2 = c + DC[d];
      if (r2 < 0 || r2 >= N) continue;
      if (c2 < 0 || c2 >= G[r2].size()) continue;
      if (G[r2][c2] != '.') continue;
      ++res, G[r2][c2] = '#', Q.emplace(r2, c2);
    }
  }
  return res;
}

void fill() {
  for (int r = 0; r < N; ++r) for (int c = 0; c < G[r].size(); ++c) {
    if (G[r][c] != '.') continue;
    C.push_back(fill(r, c));
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int h;
  cin >> h >> N >> M;
  cin.ignore();
  G.resize(N);
  for (auto &row : G) getline(cin, row);
  fill();
  sort(C.rbegin(), C.rend());
  int res = 0;
  for (auto &c : C) {
    if (h <= 0) break;
    h -= c, ++res;
  }
  printf("%d\n", res);
  return 0;
}
