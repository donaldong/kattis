#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> to_base3(int n) {
  vector<int> res;
  while (n) {
    int r = n % 3;
    res.push_back(r);
    n /= 3;
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    auto N = to_base3(n);
    vector<ll> L, R;
    ll cur = 1;
    for (int i = 0; i < N.size() - 1; ++i) {
      N[i + 1] += N[i] / 3;
      N[i] %= 3;
      if (N[i] == 2) {
        L.push_back(cur);
        N[i] = 0;
        N[i + 1]++;
      } else if (N[i] == 1) {
        R.push_back(cur);
      }
      cur *= 3;
    }
    while (N.back()) {
      int k = N.back() / 3;
      N.back() %= 3;
      if (N.back() == 2) {
        L.push_back(cur);
        ++k;
      } else if (N.back() == 1) {
        R.push_back(cur);
      }
      N.push_back(k);
      cur *= 3;
    }
    cout << "left pan: ";
    while (!L.empty()) {
      cout << L.back() << " ";
      L.pop_back();
    }
    cout << endl << "right pan: ";
    while (!R.empty()) {
      cout << R.back() << " ";
      R.pop_back();
    }
    cout << endl << endl;
  }
  return 0;
}
