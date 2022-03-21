#include <bits/stdc++.h>
using namespace std;
unsigned long long dfs(unsigned long long n) {
  if (n == 1) return 1;
  if (n % 2) return n+dfs(3*n+1);
  return n+dfs(n/2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  unsigned long long n;
  cin >> n;
  cout << dfs(n) << endl;
  return 0;
}
