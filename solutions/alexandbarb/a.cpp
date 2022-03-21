#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  unsigned K, L, R;
  cin >> K >> L >> R;
  auto r = K % (L+R);
  if (r >= L) cout << "Alex" << endl;
  else cout << "Barb" << endl;
  return 0;
}
