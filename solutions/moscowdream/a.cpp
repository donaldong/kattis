#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c,n;
  cin >> a >> b >> c >> n;
  if (!a || !b || !c) cout << "NO" << endl;
  else {
    --a, --b, --c, n -= 3;
    cout << (a+b+c>=n && n>=0 ? "YES" : "NO") << endl;
  }
  return 0;
}
