#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using ll = long long;

int main() {
  ll l, m, p, c, t, r, k;
  cin >> l >> m;
  cin.ignore();
  string line, token;
  ll min_cost = 1e18;
  vs res;
  while (m--) {
    getline(cin, line);
    stringstream ss(line);
    string name;
    getline(ss, name, ',');
    getline(ss, token, ',');
    p = stoi(token);
    getline(ss, token, ',');
    c = stoi(token);
    getline(ss, token, ',');
    t = stoi(token);
    getline(ss, token, ',');
    r = stoi(token);
    k = l * (t + r);
    k -= c * t * 10080;
    if (p < min_cost && k <= 0) {
      res.clear();
      min_cost = p;
    }
    if (k <= 0 && p <= min_cost) res.push_back(name);
  }
  if (res.empty()) cout << "no such mower" << endl;
  else for (string &s : res) cout << s << endl;
  return 0;
}
