#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k, r;
  cin >> k >> r;
  vector<int> amounts(k);
  for (int &v : amounts) cin >> v;

  int maxProfit = 0;
  while (r--)  {
    int a = INT_MAX, v;
    for (int i = 0; i < k; ++i) {
      cin >> v;
      a = min(a, v==0?INT_MAX:(amounts[i]/v));
    }
    cin >> v;
    maxProfit = max(maxProfit, a*v);
  }
  cout << maxProfit << endl;
  return 0;
}
