#include <bits/stdc++.h>
using namespace std;

using Num = int;
using Nums = vector<Num>;

int main() {
  int c, d, n;
  cin >> c;
  while (c--) {
    cin >> d >> n;
    Nums S(d, 0);
    int res = 0;
    int sum = 0;
    while (n--) {
      int x;
      cin >> x;
      ++S[sum];
      sum = (sum + x) % d;
      res += S[sum];
    }
    cout << res << endl;
  }
  return 0;
}

