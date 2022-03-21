#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  vector<int> nums(k);
  vector<int> rank(k);
  for (int& n : nums) cin >> n;
  for (int i = 0; i < k; ++i) rank[i] = i;
  sort(rank.begin(), rank.end(), [&](int a, int b) {
    return nums[a]<nums[b];
  });
  int res = 0;
  int v = 0;
  while (!rank.empty()) {
    vector<int> rank2;
    rank2.reserve(rank.size());
    for (int n : rank) {
      if (n == v) ++v;
      else rank2.push_back(n);
    }
    swap(rank2, rank);
    ++res;
  }
  cout << res << endl;
  return 0;
}
