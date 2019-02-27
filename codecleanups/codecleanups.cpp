#include <bits/stdc++.h>
using namespace std;

using dq = deque<int>;

int score(const dq &Q, int t) {
  int res = 0;
  for (int i = Q.size(); i-- > 0;) {
    res += t - Q[i];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n;
  dq Q;
  int res = 0;
  while (n--) {
    cin >> d;
    if (score(Q, d) >= 20) {
      ++res;
      Q.clear();
    }
    Q.push_back(d);
#ifdef DEBUG
    for (auto q : Q) cout << q << ' ';
    cout << endl;
#endif
  }
  if (!Q.empty()) ++res;
  printf("%d\n", res);
  return 0;
}
