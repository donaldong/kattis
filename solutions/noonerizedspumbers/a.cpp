#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<string> nums(3);
  char op, eq;
  cin >> nums[0] >> op >> nums[1] >> eq >> nums[2];
  vector<vector<string>> A(3), B(3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j+1 < nums[i].size(); ++j) {
      A[i].push_back(nums[i].substr(0, j+1));
      B[i].push_back(nums[i].substr(j+1));
    }
  }
  auto apply = [&](string a, string b, string c) -> bool {
    unsigned long long x = stoull(a), y = stoull(b), z = stoull(c);
    if (x > z || y > z) return false;
    if (op == '+') {
      if (x+y==z) {
        printf("%lld + %lld = %lld\n",x,y,z);
        return true;
      }
      return false;
    }
    if (x*y==z) {
      printf("%lld * %lld = %lld\n",x,y,z);
      return true;
    }
    return false;
  };
  for (int i = 0; i < A[0].size(); ++i) {
    for (int j = 0; j < A[1].size(); ++j) {
      if (apply(A[1][j]+B[0][i],A[0][i]+B[1][j],nums[2])) return 0;
    }
  }
  for (int i = 0; i < A[0].size(); ++i) {
    for (int j = 0; j < A[2].size(); ++j) {
      if (apply(A[2][j]+B[0][i],nums[1],A[0][i]+B[2][j])) return 0;
    }
  }
  for (int i = 0; i < A[1].size(); ++i) {
    for (int j = 0; j < A[2].size(); ++j) {
      if (apply(nums[0],A[2][j]+B[1][i],A[1][i]+B[2][j])) return 0;
    }
  }
  return 0;
}
