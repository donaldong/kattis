#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  long long res = 0;
  int cur = 0;
  for (char c : s) {
    if (c > '0') ++cur;
    else res += cur;
  }
  cur = 0;
  for (char c : s) {
    if (c > '1') ++cur;
    else if (c == '1') res += cur;
  }
  printf("%lld\n", res);
  return 0;
}
