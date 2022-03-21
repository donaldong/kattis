#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p, s;
  cin >> n >> p >> s;
  while (s--) {
    int m, c;
    cin >> m;
    bool keep = false;
    while (m--) {
      cin >> c;
      if (c == p) keep = true;
    }
    cout << (keep?"KEEP":"REMOVE") << endl;
  }
  return 0;
}
