#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  char c;
  cin >> n;
  vector<int> A(n + 1, 0), B(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    if (c == 'A') {
      A[i] = A[i - 1];
      B[i] = min(A[i - 1], B[i - 1]) + 1;
    } else {
      B[i] = B[i - 1];
      A[i] = min(A[i - 1], B[i - 1]) + 1;
    }
  }
  cout << A.back() << endl;
  return 0;
}
