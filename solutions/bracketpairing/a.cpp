#include <bits/stdc++.h>
using namespace std;
/*
0123456789
((<{}>??])
*/
string s;
vector<vector<long long>> dp;

int count(int l, int r) {
  if (s[l] == '(' && s[r] ==  ')') return 1;
  if (s[l] == '[' && s[r] ==  ']') return 1;
  if (s[l] == '{' && s[r] ==  '}') return 1;
  if (s[l] == '<' && s[r] ==  '>') return 1;
  switch (s[r]) {
    case '(': case '[': case '{': case '<': return 0;
  }
  switch (s[l]) {
    case ')': case ']': case '}': case '>': return 0;
  }
  if (s[l] == '?' && s[r] == '?') return 4;
  if (s[l] == '?' || s[r] == '?') return 1;
  return 0; // mismatch
}

long long dfs(int l, int r) {
  if (l >= r) return 1;
  if (dp[l][r] >= 0) return dp[l][r];
  long long res = 0;
  for (int m = l+1; m <= r; m+=2) {
    res += count(l,m)*dfs(l+1,m-1)*dfs(m+1,r);
  }
#ifdef DEBUG
  printf("dp[%d][%d]=%lld\n",l,r,res);
#endif
  return dp[l][r] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  dp.assign(s.size(), vector<long long>(s.size(), -1));
  cout << dfs(0, s.size()-1) << endl;
  return 0;
}
