#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  deque<int> W;
  int res = 0;
  for (int r = 0; r < 2; ++r) {
    for (int i = 0; i < n; ++i) {
      int w;
      cin >> w;
      if (W.empty()) W.push_back(w);
      else if (w < W.front()) res = max(res , w);
      else if (w > W.front()) {
        res = max(res, W.front());
        W.clear();
        W.push_back(w);
      } else if (w == W.front()) {
        W.clear();
      }
    }
    while (!W.empty()) {
      res = max(res, W.back());
      W.pop_back();
    }
  }
  cout << res << endl;
  return 0;
}
