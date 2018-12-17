#include <bits/stdc++.h>
using namespace std;

int MAX_DAYS = 366;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n;
  vector<int> counts(MAX_DAYS, 0);
  while (n--) {
    cin >> a >> b;
    ++counts[a - 1];
    --counts[b];
  }
  int res = 0;
  for (size_t i = 1; i < counts.size(); ++i) {
    counts[i] += counts[i - 1];
    if (counts[i] >= 1) ++res;
  }
  if (counts[0]) ++res;
  cout << res << endl;
  return 0;
}
