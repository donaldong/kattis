#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

int main() {
  int n, s, r;
  cin >> n >> s >> r;
  vi S(s);
  vb T(n + 1, false);
  for (int &num : S) cin >> num;
  while (r--) {
    int num;
    cin >> num;
    T[--num] = true;
  }
  int res = 0;
  for (auto s : S) {
    if (T[s]) continue;
    int a = s - 1, b = s + 1;
    if (0 <= a && a < T.size() && T[a]) {
      T[a] = false;
      continue;
    }
    if (0 <= b && b < T.size() && T[b]) {
      T[b] = false;
      continue;
    }
    ++res;
  }
  cout << res << endl;
  return 0;
}
