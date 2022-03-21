#include <bits/stdc++.h>
using namespace std;
bool possible(string& a, string &b) {
  if (a.size() < b.size()) return false;
  string c = b;
  for (int i = 0; i < a.size(); ++i) {
    char t = c[i];
    if (i == 0) {
      if (b.size() == 1) c[i] = '0';
      else c[i] = '1';
    }
    else c[i] = '0';
    if (a > c) {
      b = c;
      return true;
    }
    c[i] = t;
  }
  c = a;
  for (int i = 0; i < a.size(); ++i) {
    char t = c[i];
    c[i] = '9';
    if (c > b) {
      a = c;
      return true;
    }
    c[i] = t;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> nums(n);
  for (auto& num : nums) cin >> num;
  bool f = false;
  for (int i = 1; i < n; ++i) {
    if (possible(nums[i-1], nums[i])) {
      f = true;
      break;
    }
  }
  if (!f) cout << "impossible" << endl;
  else {
    for (auto& num : nums) cout << num << ' ';
    cout << endl;
  }
  return 0;
}
