#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int h, n, m;
  cin >> h >> n >> m;
  int A = 1, B = 0;
  for (int i = 2; i <= h; ++i) {
    B+= (i-1)*4/2;
  }
#ifdef DEBUG
    printf("A=%d, B=%d\n", A, B);
#endif
  int C = max(A+2*B-n, 0);
  if (C-2*m >= 0) C -= 2*m;
  else C=C%2;
  int a = C%2?1:0, b = C/2;
#ifdef DEBUG
  printf("C=%d\n", C);
#endif
  cout << a << ' '<< b << endl;
  return 0;
}
