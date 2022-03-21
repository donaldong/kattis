#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    int v;
    cin >> v;
    sum += v;
  }
  cout << (double)(sum-(n-k)*3)/n << ' ' << (double)(sum+(n-k)*3)/n << endl;
  return 0;
}
