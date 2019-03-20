#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool valid(int n, int b) {
  vi D;
  while (n) {
    D.push_back(n % b);
    n /= b;
  }
  int i = 0, j = D.size() - 1;
  while (i < j) {
    if (D[i] != D[j]) return false;
    ++i, --j;
  }
  return true;
}

int solve(int a, int b, int k) {
  vi A;
  for (int i = a; i <= b; ++i) {
    if (valid(i, 2)) A.push_back(i);
  }
  for (int i = 3; i <= k; ++i) {
    vi B;
    for (int e : A) if (valid(e, i)) B.push_back(e);
    A = B;
    if (A.empty()) return 0;
  }
  return A.size();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, k;
  cin >> a >> b >> k;
  printf("%d\n", solve(a, b, k));
  return 0;
}
