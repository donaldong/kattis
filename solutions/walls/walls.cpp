#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int L, W, N, R;
ld L_2, W_2;

int DL[] = {-1, 1, 0, 0};
int DW[] = {0, 0, -1, 1};

// Cranes
vector<tuple<int, int>> C;
// Positions
vector<tuple<ld, ld>> P;

bool reachable(tuple<int, int> &t, tuple<ld, ld> &p) {
  int x1, y1;
  ld x2, y2;
  tie(x1, y1) = t;
  tie(x2, y2) = p;
  ld dx = x2 - x1;
  ld dy = y2 - y1;
  return int(dx * dx + dy * dy) <= R * R;
}

bool possible(vector<tuple<int, int>> opts) {
  vector<bool> M(4, false);
  for (auto &opt : opts) {
    for (int j = 0; j < 4; ++j) {
      if (reachable(opt, P[j])) M[j] = true;
    }
  }
  return all_of(M.begin(), M.end(), [](bool f) { return f; });
}

vector<bool> solve() {
  vector<bool> R(3, false);
  for (int i = 0; i < N; ++i) {
    if (possible({C[i]})) {
      R[0] = true;
      return R;
    }
    for (int j = i + 1; j < N; ++j) {
      if (possible({C[i], C[j]})) {
        R[1] = true;
      }
      if (R[1]) continue;
      for (int k = j + 1; k < N; ++k) {
        if (possible({C[i], C[j], C[k]})) {
          R[2] = true;
        }
      }
    }
  }
  return R;
}

int main() {
  cin >> L >> W >> N >> R;
  L_2 = L, W_2 = W;
  L_2 /= 2, W_2 /= 2;
  C = vector<tuple<int, int>>(N);
  P = vector<tuple<ld, ld>>(4);
  // Movable at position i
  vector<bool> M(4, false);
  for (int i = 0; i < 4; ++i) {
    P[i] = make_tuple(DL[i] * L_2, DW[i] * W_2);
  }
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    C[i] = make_tuple(x, y);
    for (int j = 0; j < 4; ++j) {
      if (reachable(C[i], P[j])) M[j] = true;
    }
  }
  if (any_of(M.begin(), M.end(), [](bool f) { return !f; })) {
    cout << "Impossible" << endl;
    return 0;
  }
  // Results
  auto R = solve();
  if (none_of(R.begin(), R.end(), [](bool f) { return f; })) {
    cout << 4 << endl;
    return 0;
  }
  for (int i = 0; i < 4; ++i) {
    if (R[i]) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
