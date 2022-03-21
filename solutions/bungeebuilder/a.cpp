#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> H(N);
  for (int& h : H) cin >> h;
  int res = 0;
  auto calc = [&]() {
    int prevH = 0, minH = INT_MAX;
    for (int h : H) {
      if (h >= prevH) {
        if (prevH > minH) res = max(res, prevH - minH);
        prevH = h, minH = INT_MAX;
        continue;
      }
      minH = min(minH, h);
    }
  };
  calc();
  reverse(H.begin(), H.end());
  calc();
  cout << res << endl;
  return 0;
}
