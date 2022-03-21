#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string drink;
  cin >> n >> drink;
  auto s = drink.c_str();
  for (int i = n; i >= 2; --i) {
    printf(R"(
%d bottles of %s on the wall, %d bottles of %s.
Take one down, pass it around, %d bottle%s of %s on the wall.
)", i, s, i, s, i-1, i-1==1?"":"s", s);
  }
  printf(R"(
1 bottle of %s on the wall, 1 bottle of %s.
Take it down, pass it around, no more bottles of %s.
)", s, s, s);
  return 0;
}
