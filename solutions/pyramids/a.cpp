#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long w = -1, h = 0, a = 1;
  n -= 1;
  while (n >= 0) {
    ++h;
    w += 2;
    a += 4*w+4;
    n -= a;
  }
  cout << h << endl;
  return 0;
}
