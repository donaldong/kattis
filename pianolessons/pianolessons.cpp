#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int SIZE_S, SIZE_T; // Number of students, Number of time slots
v2i G; // Students -> Time Slot
vi vis, match; // global vars for finding an aug path

bool aug(int s) {
  if (vis[s]) return false;
  vis[s] = true;
  for (int t : G[s]) {
    if (match[t] < 0 || aug(match[t])) {
      match[t] = s;
      return true;
    }
  }
  return false;
}

int max_match() {
  int count = 0;
  match.assign(SIZE_T, -1);
  for (int s = 0; s < SIZE_S; ++s) {
    vis.assign(SIZE_S, 0);
    count += aug(s);
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> SIZE_S >> SIZE_T;
  G.resize(SIZE_S);
  int k, t;
  for (int s = 0; s < SIZE_S; ++s) {
    cin >> k;
    while (k--) cin >> t, G[s].push_back(t - 1);
  }
  printf("%d\n", max_match());
  return 0;
}
