#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
int MAX_STATES = 1 << 19;
vi T(MAX_STATES, -1);

int get_state(vi &V) {
  int res = 0;
  for (int i = 0; i < 9; ++i) {
    res <<= 2;
    res += V[i];
  }
  return res;
}

int index(int r, int c) { return 3 * r + c; }

int new_state(int s, int p) {
  vi S(9);
  for (int i = 8; i >= 0; --i) {
    S[i] = s & 3;
    s >>= 2;
  }
  int r = p / 3, c = p % 3;
  for (int i = 0; i < 3; ++i) {
    int a = index(r, i), b = index(i, c);
    --S[a], --S[b];
  }
  ++S[index(r, c)];
  for (int i = 0; i < 3; ++i) {
    int a = index(r, i), b = index(i, c);
    if (S[a] < 0) S[a] += 4;
    if (S[b] < 0) S[b] += 4;
  }
  return get_state(S);
}

int main() {
  int step, cur = 0;
  queue<tuple<int, int>> Q;
  Q.emplace(0, cur);
  while (!Q.empty()) {
    tie(step, cur) = Q.front(); Q.pop();
    for (int i = 0; i < 9; ++i) {
      int ns = new_state(cur, i);
      if (T[ns] == -1) {
        T[ns] = step + 1;
        Q.emplace(step + 1, ns);
      }
    }
  }
  vi V(9);
  for (int &v : V) cin >> v;
  cout << T[get_state(V)] << endl;
  return 0;
}
