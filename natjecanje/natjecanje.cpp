#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
  int n, s, r;
  cin >> n >> s >> r;
  vi S(s), R(r);
  for (int &num : S) cin >> num;
  for (int &num : R) cin >> num;
  sort(S.rbegin(), S.rend());
  sort(R.begin(), R.end());
  for (int i = 0; i < r; ++i) {
    if (!S.empty() && abs(S.back() - R[i]) <= 1) S.pop_back();
  }
  cout << S.size() << endl;
  return 0;
}
