#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  unordered_map<string,pair<int,string>> m;
  while (n--) {
    string name, date;
    int rank;
    cin >> name >> rank >> date;
    m[date] = max(m[date], make_pair(rank, name));
  }
  vector<string> res;
  res.reserve(m.size());
  for (auto& [d, p] : m) {
    const auto& [_, name] = p;
    res.push_back(name);
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (auto& r: res) cout << r << endl;
  return 0;
}
