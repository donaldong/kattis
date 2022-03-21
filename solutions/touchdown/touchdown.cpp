#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi N;

int solve() {
  int cur = 20;
  for (int i = 0; i < N.size();) {
    int tot = 0;
    for (int j = 0; j < 4 && i < N.size() && tot < 10; ++j, ++i) {
      cur += N[i];
      if (cur >= 100) return 1;
      if (cur <= 0) return 2;
      tot += N[i];
    }
    if (tot < 10) return 0;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  N.resize(n);
  for (auto &e : N) cin >> e;
  switch (solve()) {
    case 0: printf("Nothing\n"); break;
    case 1: printf("Touchdown\n"); break;
    case 2: printf("Safety\n"); break;
  }
  return 0;
}
