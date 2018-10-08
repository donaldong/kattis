#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;

int MAX_NUM = 3001;
v3i C; // Cards
v2i R; // For each card, each number, the row number

bool get_list(int a, int b, int s, vi &L) {
  int ra, rb;
  if ((ra = R[a][s]) == -1 || (rb = R[b][s]) == -1) return false;
  for (int num : C[a][ra]) if (num != s) L.push_back(num);
  for (int num : C[b][rb]) if (num != s) L.push_back(num);
  sort(L.begin(), L.end());
  auto itr = unique(L.begin(), L.end());
  L.resize(itr - L.begin());
  return true;
}

bool bingo(int c, const vi &L) {
  vi count(5, 0);
  for (int l : L) if (R[c][l] != -1) ++count[R[c][l]];
  for (int c : count) if (c >= 5) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  C.assign(n, v2i(5, vi(5)));
  R.assign(n, vi(MAX_NUM, -1));
  vi count(MAX_NUM, 0);
  for (int c = 0; c < n; ++c) for (int r = 0; r < 5; ++r) {
    for (auto &num : C[c][r]) {
      cin >> num; ++count[num];
      R[c][num] = r;
    }
  }
  // Find duplicates across all cards
  vi S;
  for (int s = 1; s < MAX_NUM; ++s) if (count[s] > 1) S.push_back(s);
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
    for (int s : S) {
      // Potential tie seq
      vi L;
      bool f = get_list(i, j, s, L);
      if (!f) continue;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;
        if (bingo(k, L)) {
          f = false;
          break;
        }
      }
      if (f) { 
        printf("%d %d\n", i + 1, j + 1);
        return 0;
      }
    }
  }
  printf("no ties\n");
  return 0;
}
