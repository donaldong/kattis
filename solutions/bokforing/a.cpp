#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q, round = 0, base = 0;
  cin >> n >> q;
  vector<pair<int,int>> P(n, {0,0});
  while (q--) {
    string s;
    cin >> s;
    int a, b;
    switch (s[0])  {
    case 'P': {
      cin >> a;
      auto [r, v] = P[a-1];
      printf("%d\n", r<round ? base : v);
      break;
    }

    case 'S': {
      cin >> a >> b;
      P[a-1] = {round, b};
      break;
    }

    case 'R': {
      cin >> base;
      ++round;
      break;
    }
    }
  }
  return 0;
}
