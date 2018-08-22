#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  while (cin >> N) {
    if (!N) break;
    vector<tuple<int, int>> P(N);
    for (int i = 0; i < N; ++i) {
      int x, y;
      cin >> x >> y;
      P[i] = make_tuple(x, y);
    }
    int x0, y0;
    tie(x0, y0) = P[N / 2];
    int S = 0, O = 0;
    for (int i = 0; i < N; ++i) {
      int x, y;
      tie(x, y) = P[i];
      x -= x0;
      y -= y0;
      if (x > 0 && y > 0) ++S;
      else if (x < 0 && y < 0) ++S;
      if (x < 0 && y > 0) ++O;
      else if (x > 0 && y < 0) ++O;
    }
    cout << S << " " << O << endl;
  }
  return 0;
}
