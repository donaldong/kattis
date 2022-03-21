#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  unordered_set<int> s;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    s.insert(k);
  }
  for (int i = 1; i < n; ++i) {
    int k;
    cin >> k;
    s.erase(k);
  }
  cout << *s.begin() << endl;
  return 0;
}
