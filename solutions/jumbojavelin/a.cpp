#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int sum=-n+1;
  while (n--) {
    int v;
    cin >> v;
    sum += v;
  }
  cout << sum << endl;
  return 0;
}
