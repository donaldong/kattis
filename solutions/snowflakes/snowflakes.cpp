#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    size_t res = 0, f, k;
    queue<int> Q;
    unordered_set<int> S;
    cin >> n;
    while (n--) {
      cin >> k;
      if (S.find(k) != S.end()) {
        while (!Q.empty() && Q.front() != k) {
          f = Q.front(), Q.pop();
          S.erase(f);
        }
        if (!Q.empty() && Q.front() == k) {
          f = Q.front(), Q.pop();
          S.erase(f);
        }
      }
      S.insert(k), Q.push(k);
      res = max(res, Q.size());
    }
    printf("%lu\n", res);
  }
  return 0;
}
