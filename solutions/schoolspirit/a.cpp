#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> S(n);
  for (int& s : S) cin >> s;
  vector<double> R(n+1);
  R[0] = 1.0;
  for (int i = 1; i <= n; ++i) R[i] = R[i-1]*4.0/5.0;
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    sum += S[i]*R[i];
  }
  cout << setprecision(10) << sum/5 << endl;
  sum = 0.0;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      sum += R[k++]*S[j];
    }
  }
  cout << setprecision(10) << sum/5.0/n << endl;
  return 0;
}
