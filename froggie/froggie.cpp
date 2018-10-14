#include <bits/stdc++.h>
using namespace std;

int L, W;
using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
using vb = vector<bool>;
vti3 lanes;

vb get_lane(int t, int r) {
  vb res(W, false);
  if (r == L) return res;
  int o, i, s;
  tie(o, i, s) = lanes[r];
  int cur = o - i + (t * s) % i;
  while (cur < W) {
    for (int j = 1; j <= s; ++j) {
      if (cur + j < 0 || cur + j >= W) continue;
      res[cur + j] = true;
    }
    cur += i;
  }
  if (r & 1) reverse(res.begin(), res.end());
  return res;
}

bool okay(int t, char opt, int &r, int &c) {
  if (opt == 'U') --r;
  else if (opt == 'D') ++r;
  else if (opt == 'L') --c;
  else ++c;
  if (r < 0) return true;
  return !get_lane(t, r)[c];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> W;
  lanes.reserve(L);
  int o, i, s;
  for (int j = 0; j < L; ++j) {
    cin >> o >> i >> s;
    lanes.emplace_back(o, i, s);
  }
  int r = L, c;
  string moves;
  bool safe = true;
  cin >> c >> moves;
  for (size_t t = 0; t < moves.size(); ++t) {
    if (!okay(t, moves[t], r, c)) {
      safe = false; break;
    }
  }
  cout << (safe && r <= 0 ? "safe" : "squish") << endl;
  return 0;
}
