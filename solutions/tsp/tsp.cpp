#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using vld = vector<ld>;
using v2ld = vector<vld>;
using vi = vector<int>;
using vb = vector<bool>;
ld INF = 1e18;
vi tour;
int N;
vld X, Y;
v2ld D;

void debug(vi &V) {
  for (int v : V) cout << v << " ";
  cout << endl;
}

bool vswap(int i, int j) {
  ld dist = D[tour[i - 1]][tour[j]] + D[tour[i]][tour[j + 1]];
  dist -= D[tour[i - 1]][tour[i]] + D[tour[j]][tour[j + 1]];
  return dist < 0;
}

ld tour_dist() {
  ld res = 0;
  for (size_t i = 1; i < tour.size(); ++i) {
    res += D[tour[i]][tour[i - 1]];
  }
  return res;
}

bool dist_swap() {
  for (size_t i = 1; i < tour.size() - 2; ++i) {
    for (size_t j = i + 2; j < tour.size() - 1; ++j) {
      if (vswap(i, j)) {
        reverse(tour.begin() + i, tour.begin() + j + 1);
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ld x, y;
  cin >> N;
  vb used(N, false);
  tour.assign(N, -1);
  D.assign(N, vld(N, -1));
  X.assign(N, 0.0);
  Y.assign(N, 0.0);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) D[i][j] = D[j][i];
    for (int j = i + 1; j < N; ++j) {
      x = X[i] - X[j], y = Y[i] - Y[j];
      D[i][j] = hypot(x, y);
    }
  }
  tour[0] = 0;
  used[0] = true;
  for (int i = 1; i < N; ++i) {
    int best = -1;
    for (int j = 0; j < N; ++j) {
      if (used[j]) continue;
      if (best == -1 || D[tour[i - 1]][j] < D[tour[i - 1]][best]) {
        best = j;
      }
    }
    used[best] = true;
    tour[i] = best;
  }
  tour.push_back(0);
  while (dist_swap());
  tour.pop_back();
  for (int t : tour) cout << t << endl;
  return 0;
}
