#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string x, y;
  cin >> x >> y;
  if (x > y) swap(x, y);
  if (x == "0") cout << "0" << endl;
  else {
    int a = 0, b = 0;
    for (char c : x) if (c == 'S') ++a;
    for (char c : y) if (c == 'S') ++b;
    int k = a*b;
    for (int i = 0; i < k; ++i) cout << "S(";
    cout << "0";
    for (int i = 0; i < k; ++i) cout << ")";
    cout << endl;
  }
  return 0;
}
