#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int p, D;
  cin >> p >> D;
  vector<long long> A(D, 0), B(D, 0);
  long long wa = 0, wb = 0;
  long long V = 0;
  while (p--) {
    long long a, b, d;
    cin >> d >> a >> b;
    --d;
    A[d] += a, B[d] += b;
    V += a + b;
  }
  for (int i = 0; i < D; ++i) {
    if (A[i]>B[i]) {
      long long da = A[i]-(A[i]+B[i])/2-1;
      long long db = B[i];
      printf("A %lld %lld\n", da, db);
      wa += da, wb += db;
    } else {
      long long db = B[i]-(A[i]+B[i])/2-1;
      long long da = A[i];
      printf("B %lld %lld\n", da, db);
      wa += da, wb += db;
    }
  }
  printf("%.10f\n", abs((double)wa-wb)/V);
  return 0;
}
