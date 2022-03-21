#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<long long> L, R;

long long left(int i) {
  if (L[i] > LLONG_MIN) return L[i];
  long long res = i;
  res *= A[i-1];
  return L[i] = res + left(i-1);
}

long long right(int i) {
  if (R[i] > LLONG_MIN) return R[i];
  long long res = i+2;
  res *= A[i];
  return R[i] = res + right(i+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  A.resize(n-1);
  for (int i = 0; i+1 < n; ++i) {
    cin >> A[i];
    if (!A[i]) cin >> A[i];
  }
  L.assign(n, LLONG_MIN);
  L[0] = 0;
  R.assign(n, LLONG_MIN);
  R[n-1] = 0;
  long long res = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    res = max(res, left(i) + right(i));
  }
  cout << res << endl;
  return 0;
}
