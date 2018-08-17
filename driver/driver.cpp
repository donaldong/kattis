#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;

// Road: cost
vector<int> R;
// Gate: time when the gate is open
vector<int> G;

bool even(ll &n) {
  return !(n & 1);
}

ll solve() {
  // Counts for each road 
  vector<int> C(R.size());
  ll t = 0;
  for (size_t i = 0; i < C.size(); ++i) {
    if (t >= G[i + 1]) {
      C[i] = 1;
      ++t;
    } else {
      ll d = G[i + 1] - t;
      if (even(d)) ++d;
      C[i] = d;
      t += d;
    } 
  }
  // Ordered by cost, <cost, src_index>
  set<pair<int, int>> S;
  for (int i = 0; i < R.size(); ++i) {
    S.insert(make_pair(R[i], i));
  }
  // Traverse backwards and update the counts
  for (int i = C.size() - 1; i >= 0; --i) {
    auto best = S.begin();
    int move = C[i] - 1;
    C[i] = 1;
    C[best->second] += move;
    S.erase(S.find(make_pair(R[i], i)));
  }
  ll res = 0;
  for (size_t i = 0; i < C.size(); ++i) {
    ll d = C[i];
    res += d * R[i];
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  R = vector<int>(n - 1);
  G = vector<int>(n);
  for (size_t i = 0; i < R.size(); ++i) {
    cin >> R[i];
  }
  for (size_t i = 0; i < G.size(); ++i) {
    cin >> G[i];
  }
  cout << solve() << endl;
  return 0;
}
