#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int INF = 1e9;

vi P;

void build() {
  for (int i = 100; i <= 999; ++i) {
    string s = to_string(i);
    string rs = s;
    reverse(rs.begin(), rs.end());
    P.push_back(stoi(s + rs));
  }
}

int dist(vi::iterator itr, int n) {
  if (itr == P.end()) return INF;
  return abs(*itr - n);
}

int main() {
  build();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto itr = lower_bound(P.begin(), P.end(), n);
    int diff, res;
    diff = dist(itr, n);
    res = *itr;
    if (itr != P.begin()) {
      if (dist(--itr, n) <= diff) {
        res = *itr;
      }
    }
    cout << res << endl;
  }
  return 0;
}
