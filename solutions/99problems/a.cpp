/**
 * @date        2022-05-09
 * @tags        implementation
 * @difficulty  1200
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int maxNum = 1e4;
  set<int> nums;
  for (int i = 99; i <= maxNum; ++i) {
    if (i%100 != 99) continue;
    nums.insert(i);
  }
  int num, minDiff = INT_MAX,  res;
  cin >> num;
  auto itr = nums.lower_bound(num);
  if (itr == nums.end()) {
    res = *prev(itr);
  } else {
    res =  *itr;
    minDiff = abs(res - num);
    if (itr != nums.begin()) {
      int num2 = *prev(itr);
      int diff = abs(num2 - num);
      if (diff < minDiff) res = num2;
    }
  }
  cout << res << endl;
  return 0;
}
