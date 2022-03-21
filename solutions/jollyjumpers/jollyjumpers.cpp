#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  while (cin >> N) {
    vector<bool> B(N, false);
    int a, b, d;
    cin >> a;
    B[0] = true;
    for (int i = 1; i < N; ++i) {
      cin >> b;
      d = abs(a - b);
      if (d < N) B[d] = true;
      swap(a, b);
    }
    if (any_of(B.begin(), B.end(), [](bool f) { return !f; })) cout << "Not jolly" << endl;
    else cout << "Jolly" << endl;
  }
  return 0;
}
