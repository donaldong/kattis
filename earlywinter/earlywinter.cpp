#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int solve(const vi &D, int m) {
  int i;
  for (i = 0; i < D.size(); ++i) {
    if (D[i] <= m) return i;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, res;
  cin >> n >> m;
  vi D(n);
  for (int &d : D) cin >> d;
  if ((res = solve(D, m)) < 0) printf("It had never snowed this early!\n");
  else printf("It hadn't snowed this early in %d years!\n", res);
  return 0;
}
