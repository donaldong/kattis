#include <bits/stdc++.h>
using namespace std;

using ld = long double;

bool impossible(string &s) {
  return s[0] == 'I';
}

int main() {
  ifstream out("4.out"), ans("4.ans");
  string a, b;
  ld x, y;
  int i = 1;
  while (getline(out, a)) {
    getline(ans, b);
    if (impossible(a) || impossible(b)) {
      cout << i << " " << a << " " << b << endl;
    } else {
      x = stold(a);
      y = stold(b);
      printf("%d out:%.2Lf ans:%.2Lf diff: %.8Lf\n", i, x, y, abs(x - y));
    }
    ++i;
  }
  return 0;
}
