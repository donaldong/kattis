#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;

bool match(vi &h1, vi &h2, int c) {
  if (h1.size() + c > h2.size()) return false;
  int d = h2[c] - h1[0];
  if (d < 0) return false;
  for (size_t i = 1; i < h1.size(); ++i) {
    if (h2[c + i] - h1[i] != d) return false;
  }
  return true;
}

int main() {
  int c, p;
  cin >> c >> p;
  v3i targets = {
    { {0}, {0, 0, 0, 0} },
    { {0, 0} },
    { {0, 0, 1}, {1, 0} },
    { {1, 0, 0}, {0, 1} },
    { {0, 0, 0}, {0, 1}, {1, 0, 1}, {1, 0} },
    { {0, 0, 0}, {0, 0}, {0, 1, 1}, {2, 0} },
    { {0, 0, 0}, {0, 2}, {1, 1, 0}, {0, 0} }
  };
  --p;
  vi heights(c);
  for (int i = 0; i < c; ++i) cin >> heights[i];
  int count = 0;
  for (int i = 0; i < c; ++i) for (auto &h: targets[p]) {
    if (match(h, heights, i)) ++count;
  }
  cout << count << endl;
  return 0;
}
