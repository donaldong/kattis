/**
 * @date        2022-04-01
 * @tags        implementation
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  char op;
  ll a,b,resPrev=1,res;
  cin >> n;
  while (n--) {
    cin >> a >> op >> b;
    switch (op) {
    case '+':
      res = a+b-resPrev;
      break;
    case '-':
      res = (a-b)*resPrev;
      break;
    case '*':
      res = a*a*b*b;
      break;
    case '/':
      res = a>>1;
      if (a&1) ++res;
      break;
    }
    printf("%lld\n",res);
    resPrev = res;
  }
  return 0;
}
