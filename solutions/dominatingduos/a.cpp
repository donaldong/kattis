#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> N(n);
  for (int& v : N) cin >> v;
  long long res = 0;
  deque<int> Q;

  auto calc = [&]() {
    for (int d : N) {
      while (!Q.empty() && Q.back() < d) {
        Q.pop_back();
        ++res;
      }
      Q.push_back(d);
    }
  };

  calc();
  Q.clear();
  reverse(N.begin(), N.end());
  calc();
  cout << res << endl;
  return 0;
}
