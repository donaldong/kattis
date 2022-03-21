#include <bits/stdc++.h>
using namespace std;

using hset = unordered_set<string>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string a, b;
  hset S;
  cin >> n;
  cin >> a;
  bool f = true;
  S.insert(a);
  for (int i = 1; i < n; ++i) {
    cin >> b;
    if (a.back() != b[0] || S.find(b) != S.end()) {
      f = false;
      printf("Player %d lost\n", i & 1 ? 2 : 1);
      break;
    }
    a = b;
    S.insert(a);
  }
  if (f) printf("Fair Game\n");
  cout << flush;
  return 0;
}
