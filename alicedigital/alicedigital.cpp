#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    deque<int> Q;
    ll res = 0, sum = 0;
    bool seen = false;
    while (n--) {
      int k;
      cin >> k;
      if (k < m) {
        sum = 0;
        seen = false;
        Q.clear();
      } else if (k > m) {
        sum += k;
        Q.push_back(k);
      } else {
        // k == m
        sum += k;
        Q.push_back(k);
        if (!seen) {
          seen = true;
        } else {
          while (Q.front() != m) {
            sum -= Q.front();
            Q.pop_front();
          }
          sum -= m;
          Q.pop_front();
        }
      }
      if (seen) res = max(res, sum);
    }
    cout << res << endl;
  }
  return 0;
}
