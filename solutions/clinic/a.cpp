/**
 * @date        2022-03-28
 * @tags        data structure, implementation
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pair = pair<ll,string>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  ll K;
  cin >> N >> K;
  unordered_set<string> S;
  priority_queue<Pair,vector<Pair>,greater<Pair>> pq;

  auto query = [&]() -> string {
    while (!pq.empty()) {
      auto [p, m] = pq.top(); pq.pop();
      if (!S.count(m)) continue;
      return m;
    }
    return "doctor takes a break";
  };

  while (N--) {
    int Q,T;
    cin >> Q >> T;
    switch (Q) {

    case 1: {
      string M;
      ll s;
      cin >> M >> s;
      S.insert(M);
      pq.emplace(-(s-T*K), move(M));
      break;
    }

    case 2: {
      cout << query() << endl;
      break;
    }

    case 3: {
      string M;
      cin >> M;
      S.erase(M);
      break;
    }
    }
  }
  return 0;
}
