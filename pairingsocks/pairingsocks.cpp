#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi A;

int solve() {
  int res = 0;
  vi B;
  while (!A.empty()) {
#ifdef DEBUG
    printf("a: ");
    for (int i = 0; i < A.size(); ++i) printf("%d ", A[i]);
    printf("\n");
    printf("b: ");
    for (int i = 0; i < B.size(); ++i) printf("%d ", B[i]);
    printf("\n");
#endif
    while (!B.empty() && B.back() == A.back()) {
      A.pop_back(), B.pop_back();
      ++res;
    }
    if (!A.empty()) B.push_back(A.back()), A.pop_back(), ++res;
  }
  return B.empty() ? res : -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  A.resize(2 * n);
  for (int &a : A) cin >> a;
  int res = solve();
  if (res > 0) printf("%d\n", res);
  else printf("impossible\n");
  return 0;
}
