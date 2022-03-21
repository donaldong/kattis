#include <bits/stdc++.h>
using namespace std;

int L, M;

int get_index(int r, int c) {
  if (r < 0 || r >= M || c < 0 || c >= M) return -1;
  int res = r * M + c;
  return res >= L ? -1 : res;
};

int main() {
  int n;
  string msg;
  cin >> n;
  while (n--) {
    cin >> msg;
    L = msg.size();
    M = sqrt(L);
    if (M * M < L) ++M;
    for (int c = 0; c < M; ++c) for (int r = M - 1; r >= 0; --r) {
      int i = get_index(r, c);
      if (i < 0) continue;
      cout << msg[i];
    }
    cout << endl;
  }
  return 0;
}
