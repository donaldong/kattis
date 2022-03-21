#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long ones = 0, twos = 0, res = 0;
  while (n--) {
    int v;
    cin >> v;
    switch (v) {
    case 3: res = (res+twos)%mod; break;
    case 1: ++ones; break;
    case 2: twos = (twos*2+ones)%mod; break;
    }
  }
  cout << res << endl;
  return 0;
}
