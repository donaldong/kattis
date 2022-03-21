#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

int MAX_N = 1e6;
vi CR(MAX_N, 0), CC(MAX_N, 0);

ll solve(vi &V) {
  vi D(V.size(), 0);
  queue<int> Q;
  for (size_t i = 0; i < V.size(); ++i) {
    if (V[i] >= 2) D[i] = V[i] - 1;
    else if (!V[i]) Q.push(i);
  }
  ll res = 0;
  for (size_t i = 0; i < D.size(); ++i) {
    while (D[i]--) {
      ll r = i - Q.front();
      Q.pop();
      if (r < 0) r *= -1;
      res += r; 
    }
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    ++CR[r];
    ++CC[c];
  }
  cout << solve(CR) + solve(CC) << endl;
  return 0;
}
