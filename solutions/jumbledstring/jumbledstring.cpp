#include <bits/stdc++.h>
using namespace std;

int N = 44722;
using vi = vector<int>;

int main() {
  vi A(N), B(N);
  B[2] = A[1] = 1;
  A[2] = 2;
  for (int i = 3; i < N; ++i) {
    A[i] = i;
    B[i] = A[i - 1] + B[i - 1];
    cout << B[i] << endl;
  }
  return 0;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  return 0;
}
