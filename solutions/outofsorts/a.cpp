/**
 * @date        2022-03-27
 * @tags        implementation
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,m,a,c;
  long long x0;
  cin >> n >> m >> a >> c >> x0;
  vector<long long> X(n);
  X[0] = (a*x0+c)%m;
  for (int i = 1; i < n; ++i) X[i] = (a*X[i-1]+c)%m;

  auto canFind = [&](int v) {
    int low = 0, high = n-1; // well, I usually set high to n, but the problem is expecting n-1
    while (low <= high) {
      int mid = (low+high)/2;
      if (X[mid] == v) return true;
      if (v < X[mid]) high = mid-1;
      else low = mid+1;
    }
    return false;
  };

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (canFind(X[i])) ++res;
  }
  cout << res << endl;
  return 0;
}
