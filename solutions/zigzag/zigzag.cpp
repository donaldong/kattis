#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

inline char print(char prev, bool inc, int n, int &count) {
#ifdef DEBUG
  printf(
    "\n%c %c %d = %c  (%d char left)\n",
    prev, inc ? '+' : '-', n, inc ? prev + n : prev - n, count - n
  );
#endif
  count -= n;
  prev = inc ? prev + n : prev - n;
  printf("%c", prev);
  return prev;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int last_char = n % 25;
  int d = last_char == 0 ? 0 : (25  - last_char) / 2;

  char prev = 'a';
  bool inc = true;
  printf("%c", 'a');
  if (n <= 25) prev = print(prev, inc, n, n);
  else {
    prev = print(prev, true, 25 - d, n);
    prev = print(prev, false, min(25 - d, n), n);
    while (n > 25) {
      prev = print(prev, inc, 25, n);
      inc = !inc;
    }
    if (n > 0) print(prev, inc, n, n);
  }
  printf("\n");
  cout << flush;

  return 0;
}
