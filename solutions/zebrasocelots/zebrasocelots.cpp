#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
  int n;
  cin >> n;
  ull res = 0;
  char c;
  while (n--) {
    cin >> c;
    if (c == 'O') res = res * 2 + 1;
    else res *= 2;
  }
  cout << res << endl;
  return 0;
}
