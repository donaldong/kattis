/**
 * @date        2022-12-17
 * @tags        hash map, stack
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  unordered_map<string,vector<string>> M;
  vector<unordered_set<string>> S(1);
  string op, id, t;
  while (n--) {
    cin >> op;
    switch (op[0]) {
      case '{': S.emplace_back(); break;
      case '}': {
        for (auto& id : S.back()) M[id].pop_back();
        S.pop_back();
        break;
      }
      case 'D': {
        cin >> id >> t;
        M[id].push_back(t);
        auto& s = S.back();
        if (s.count(id)) {
          cout << "MULTIPLE DECLARATION" << endl;
          return 0;
        }
        s.insert(move(id));
        break;
      }
      case 'T': {
        cin >> id;
        auto& m = M[id];
        cout << (m.empty()?"UNDECLARED":m.back()) << '\n';
      }
    }
  }
  return 0;
}
