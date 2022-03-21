#include <bits/stdc++.h>
using namespace std;

bool possible(int m, int a, int b, int c) {
  return a + b + c <= 2 * m;
}

int main() {
  int m, a, b, c;
  cin >> m >> a >> b >> c;
  cout << (possible(m, a, b, c) ? "possible" : "impossible") << endl;
  return 0;
}
