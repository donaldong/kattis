#include <bits/stdc++.h>
using namespace std;

using ld = long double;

ld DELTA = 1e-10;
ld LOG_2 = log(2);

int main() {
  int Y;
  while (cin >> Y) {
    if (!Y) break;
    int k = Y - 1960;
    k /= 10;
    ld b = LOG_2 * pow(2, k + 2); 
    ld a = 0;
    int n = 2;
    while (true) {
      a += log(n);
      if (b - a < DELTA) break;
      ++n;
    }
    cout << n - 1 << endl;
  }
  return 0;
}
