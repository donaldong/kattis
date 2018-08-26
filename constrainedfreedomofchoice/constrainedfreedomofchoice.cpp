#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using vs = vector<string>;

int R, C;
vs G;

uint solve() {
  return 0;
}

int main() {
  while (cin >> R >> C) {
    G = vs(R);
    for (auto &row : G) cin >> row;
    cout << solve() << endl;
  }
  return 0;
}
