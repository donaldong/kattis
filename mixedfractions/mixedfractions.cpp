#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q;
  while (cin >> p >> q) {
    if (!p && !q) break;
    printf("%d %d / %d\n", p / q, p % q, q);
  }
  return 0;
}
