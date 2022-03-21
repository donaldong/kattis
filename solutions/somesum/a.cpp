#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n%2) cout << "Either" << endl;
  else {
    n/=2;
    cout << (n%2?"Odd":"Even") << endl;
  }
  return 0;
}
