#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  list<string> L;
  for (int i = 1; i <= n; ++i) {
    L.push_back("T"+to_string(i));
  }
  while (m--) {
    string a, b;
    cin >> a >> b;
    auto i = L.end();
    auto j = L.end();
    for (auto itr = L.begin(); itr != L.end(); ++itr) {
      bool found = false;
      if (*itr == a) i = itr, found = true;
      else if (*itr == b) j = itr, found = true;
      if (found) break;
    }
    if (j == L.end()) continue;
    for (i = j; i != L.end(); ++i) {
      if (*i == a) break;
    }
    L.erase(j);
    L.insert(next(i), b);
#ifdef DEBUG
  printf("DEBUG %s => %s\n", a.c_str(), b.c_str());
  for (auto& s : L) cout << s << ' ';
  cout << endl;
#endif
  }
  for (auto& s : L) cout << s << ' ';
  cout << endl;
  return 0;
}
