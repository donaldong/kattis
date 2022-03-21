#include <bits/stdc++.h>
using namespace std;
// wa?
int solve(string& A, string& B) {
  unordered_map<char,int> freq, freq2;
  for (char c : A) ++freq[c];
  for (char c : B) ++freq2[c];
  if (A.size()!=B.size() || freq['?']+freq['0']<freq2['0']) return -1;
  int res = freq['?'];
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] == '1' && B[i] == '0') ++res; // swap
  }
  if (freq['0']>=freq2['0']) {
    res += freq['0']-freq2['0']; //extra 0s turn to 1
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int j = 0; j < t; ++j) {
    string A,B;
    cin >> A >> B;
    printf("Case %d: %d\n", j+1, solve(A,B));
  }
  return 0;
}
