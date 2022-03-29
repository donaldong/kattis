/**
 * @date        2022-03-28
 * @tags        data structure
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
using Tuple = tuple<int,int,string>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  unordered_map<string, int> lvl, T;
  priority_queue<Tuple> pq;

  auto query = [&]() {
    string res;
    while (!pq.empty()) {
      auto [l, t, name] = pq.top();
      if (!lvl.count(name) || lvl[name] != l) {
        pq.pop();
        continue;
      }
      swap(res, name);
      break;
    }
    if (res.empty()) cout << "The clinic is empty" << endl;
    else cout << res << endl;
  };

  while (N--) {
    int cmd;
    cin >> cmd;
    switch (cmd) {

    case 0: {
      int l;
      string name;
      cin >> name >> l;
      lvl[name] = l, T[name] = N;
      pq.emplace(l, N, name);
      break;
    }

    case 1: {
      int l;
      string name;
      cin >> name >> l;
      lvl[name] += l;
      pq.emplace(lvl[name], T[name], name);
      break;
    }

    case 2: {
      string name;
      cin >> name;
      lvl.erase(name);
      break;
    }

    case 3: {
      query();
      break;
    }

    }
  }
  return 0;
}
