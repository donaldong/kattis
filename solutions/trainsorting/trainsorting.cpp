#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi lis(vi &N) {
  vi L(N.size(), 1);
  for (int i = N.size(); i--;) {
    for (int j = i + 1; j < N.size(); ++j) {
      if (N[j] > N[i] && L[j] + 1 > L[i]) L[i] = L[j] + 1;
    }
  }
  return L;
}

vi lds(vi &N) {
  vi L(N.size(), 1);
  for (int i = N.size(); i--;) {
    for (int j = i + 1; j < N.size(); ++j) {
      if (N[j] < N[i] && L[j] + 1 > L[i]) L[i] = L[j] + 1;
    }
  }
  return L;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, res = 0;
  cin >> n;
  vi N(n);
  for (auto &l : N) cin >> l;
  vi A = lis(N), B = lds(N);
  for (int i = 0; i < n; ++i) {
    res = max(res, A[i] + B[i] - 1);
  }
  printf("%d\n", res);
  return 0;
}
