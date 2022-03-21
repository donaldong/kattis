#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  int n, k = 0;
  cin >> n;
  vector<string> P(n);
  for (auto &p : P) cin >> p;
  for (int i = 1; i < s.size(); ++i) if (s[i]!=' '&&s[i-1]==' ') ++k;
  vector<vector<string>> res(2);
  res[0].reserve(n), res[1].reserve(n);
  for (int i = 0, p = 0, t = 0; i < n; ++i) {
    p = (p+k)%P.size();
    res[t].push_back(move(P[p]));
    t = 1-t;
    P.erase(P.begin()+p);
  }
  cout << res[0].size() << endl;
  for (auto& s : res[0]) cout << s << endl;
  cout << res[1].size() << endl;
  for (auto& s : res[1]) cout << s << endl;
  return 0;
}
