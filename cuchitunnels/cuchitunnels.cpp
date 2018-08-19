#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    sum += k;
  }
  cout << (sum == 2 * (n - 1) ? "YES" : "NO") << endl;
  return 0;
}
