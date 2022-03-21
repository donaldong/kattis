#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct rect {
  int a, b;
};

vector<rect> rects(3);
vi used(3, 0);

bool all_used() {
  for (int i : used) if (!i) return false;
  return true;
}

bool possible(int a, int b) {
  if (a < 0 || b < 0) return false;
  if ((a == 0 || b == 0) && all_used()) return true;
  for (int i = 0; i < 3; ++i) {
    if (used[i]) continue;
    auto &r = rects[i];
    used[i] = true;
#ifdef DEBUG
    printf("considering %d x %d in %d x %d\n", r.a, r.b, a, b);
#endif
    if (a == r.a && possible(a, b - r.b)) return true;
    if (a == r.b && possible(a, b - r.a)) return true;
    if (b == r.a && possible(a - r.b, b)) return true;
    if (b == r.b && possible(a - r.a, b)) return true;
    used[i] = false;
#ifdef DEBUG
    printf("%d x %d in %d x %d is impossible\n", r.a, r.b, a, b);
#endif
  }
  return false;
}

int main() {
  int side = 0;
  for (auto &r : rects) {
    cin >> r.a >> r.b;
    if (r.a > r.b) swap(r.a, r.b);
    side = max(side, r.b);
  }
  printf("%s\n", possible(side, side) ? "YES" : "NO");
  return 0;
}
