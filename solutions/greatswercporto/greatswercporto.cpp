#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
unordered_map<char, int> ID;
v2i G;
vi start(10, 0), used(10, 0), V(10);
int RES = 0;

int get_id(char c) {
  if (ID.find(c) != ID.end()) return ID[c];
  int id = ID.size();
  ID[c] = id;
  return id;
}

bool possible() {
  vi nums(G.size(), 0);
  for (int i = 0; i < G.size(); ++i) {
    for (int j = 0; j < 10; ++j) {
      int k = G[i][j];
      if (k < 0) continue;
      nums[i] = nums[i] * 10 + V[k];
    }
  }
  int tot = 0;
  for (int i = 0; i + 1 < nums.size(); ++i) tot += nums[i];
  if (tot == nums.back()) {
#ifdef DEBUG
    for (int i = 0; i < G.size(); ++i) {
      printf("%d: %d => ", i, nums[i]);
      for (int j = 0; j < 10; ++j) printf("%d ", G[i][j]);
      printf("\n");
    }
#endif
  }
  return tot == nums.back();
}

void dfs(int n) {
  if (n == ID.size()) {
    if (possible()) ++RES;
    return;
  }
  for (int i = 0; i < 10; ++i) {
    if (used[i]) continue;
    if (start[n] && !i) continue;
    used[i] = true;
    V[n] = i;
    dfs(n + 1);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  string s;
  cin >> n;
  G.assign(n, vi(10, -1));
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (size_t j = 0; j < s.size(); ++j) {
      int id = get_id(s[s.size() - j - 1] - 'A');
      if (id == 10) return printf("0\n"), 0;
      G[i][9 - j] = id;
    }
    start[get_id(s[0] - 'A')] = 1;
  }
  dfs(0);
  printf("%d\n", RES);
  return 0;
}
