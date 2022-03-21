#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
int INF = 1e9;
string OPT = "+-*/";

int calc(int a, int b, int opt) {
  if (opt == 0) return a + b;
  if (opt == 1) return a - b;
  if (opt == 2) return a * b;
  if (a % b) return INF;
  return a / b;
}

void solve(vi &N) {
  for (int i = 0; i < 4; ++i) {
    if (calc(N[0], N[1], i) == N[2]) {
      cout << N[0] << OPT[i] << N[1] << '=' << N[2] << endl;
      return;
    }
  }
  for (int i = 0; i < 4; ++i) {
    if (calc(N[1], N[2], i) == N[0]) {
      cout << N[0] << '=' << N[1] << OPT[i] << N[2] << endl;
      return;
    }
  }
}

int main() {
  vi N(3);
  for (int &n : N) cin >> n;
  solve(N);
  return 0;
}
