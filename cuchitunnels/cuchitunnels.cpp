#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

bool valid(vi &D) {
  // remove each edge sequentially
  for (size_t i = 1; i < D.size(); ++i) {
    --D[i];
    for (int j = i - 1; j >= 0; --j) {
      if (D[j]) {
        --D[j];
        break;
      } else if (j == 0) return false;
    }
  }
  for (int d : D) if (d) return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  vi D(n);
  for (auto &d : D) cin >> d;
  cout << (valid(D) ? "YES" : "NO") << endl;
  return 0;
}
