#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

bool possible(vi &row_sum, vi &col_sum) {
  vi R = row_sum, C = col_sum;
  for (int r : R) {
    sort(col_sum.rbegin(), col_sum.rend());
    for (int i = 0; i < r; ++i) {
      --col_sum[i];
      if (col_sum[i] < 0) return false;
    }
  }
  for (int c : C) {
    sort(row_sum.rbegin(), row_sum.rend());
    for (int i = 0; i < c; ++i) {
      --row_sum[i];
      if (row_sum[i] < 0) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vi row_sum(m), col_sum(n);
  for (int i = 0; i < m; ++i) cin >> row_sum[i];
  for (int i = 0; i < n; ++i) cin >> col_sum[i];
  cout << (possible(row_sum, col_sum) ? "Yes" : "No") << endl;
}
