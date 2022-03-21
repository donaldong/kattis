#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int S,N;
  cin >> S >> N;
  using Pair = pair<int,bool>;
  vector<Pair> P;
  P.reserve(N);
  for (int i = 0; i < N; ++i) {
    int d;
    char t;
    cin >> d >> t;
    P.emplace_back(d, t=='y');
  }
  sort(P.begin(), P.end(), [&](const Pair& a, const Pair& b) {
    if (a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
  });
  int t = 1;
  queue<int> T;
  for (int i = 0; i < N; ++t) {
    bool valid = true;
    for (int j = 1; valid && j < S && i < N; ++i,++j) { // handle first s-1
      auto [d, y] = P[i];
      if (y) T.push(d), --j; // not actually used
      else if (d < t) valid = false;
    }
    if (!T.empty()) {// try to pop one off T, a Y has been waiting
      int d = T.front(); T.pop();
      if (d < t) valid = false;
    } else {
      auto [d, y] = P[i++]; // use the TP stall for anyone y/n
      if (d < t) valid = false;
    }
    if (!valid) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
