#include <bits/stdc++.h>
using namespace std;

int a, b, h;

int solve() {
  int cur = 0, res = 0;
  while (1) {
    cur += a;
    ++res;
    if (cur >= h) return res;
    cur -= b;
  }
  return 0;
}

int main() {
  cin >> a >> b >> h;
  printf("%d\n", solve());
  return 0;
}
