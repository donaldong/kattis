#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
int L, H, C = 0;
vb V(10, false);

bool valid(vi &seq) {
  int n = 0;
  for (int d : seq) n = n * 10 + d;
  if (n > H || n < L) return false;
  for (int d : seq) {
    if (n % d) return false;
  }
  return true;
}

void dfs(int n, vi &seq) {
  V[n] = true;
  seq.push_back(n);
  if (seq.size() == 6) {
    if (valid(seq)) ++C;
  } else {
    for (int i = 1; i <= 9; ++i) {
      if (!V[i]) dfs(i, seq);
    }
  }
  V[n] = false;
  seq.pop_back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> H;
  for (int i = 1; i <= 9; ++i) {
    vi seq;
    dfs(i, seq);
  }
  printf("%d\n", C);
  cout << flush;
  return 0;
}
