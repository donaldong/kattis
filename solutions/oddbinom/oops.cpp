#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, res = 1;
  cin >> n;
  vi A = {1}, B = A;
  cout << 1 << endl;
  for (int i = 1; i < n; ++i) {
    B.push_back(1);
    res += 2;
    cout << 1;
    for (int j = 1; j < A.size(); ++j) {
      B[j] = (A[j - 1] + A[j]) % 2;
      if (B[j] & 1) ++res;
      cout << ' ' << B[j];
    }
    cout << ' ' << 1 << endl;
    A = B;
  }
  printf("%d\n", res);
  return 0;
}
