#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  bool won = false;
  int n, p, m, score;
  cin >> n >> p >> m;
  string name;
  unordered_map<string, int> S;
  unordered_set<string> has_won;
  while (n--) cin >> name;
  while (m--) {
    cin >> name >> score;
    int &s = S[name];
    s += score;
    if (s >= p && !has_won.count(name)) {
      printf("%s wins!\n", name.c_str());
      won = true;
      has_won.insert(name);
    }
  }
  if (!won) printf("No winner!\n");
  return 0;
}
