#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  vector<int> Y(n+k-1);
  auto P = Y;
  auto order = Y;
  for (int i = 0; i < Y.size(); ++i) {
    cin >> Y[i] >> P[i];
    order[i] = i;
  }
  priority_queue<tuple<int,int>> pq;
  sort(order.begin(), order.end(), [&](int a, int b) {
    return Y[a] < Y[b];
  });
  for (int i = 0; i+1< k; ++i) {
    int j = order[i];
    pq.emplace(P[j], j);
  }
  bool impossible = true;
  for (int i = k-1; i < Y.size(); ++i) {
    int j = order[i];
    pq.emplace(P[j], j);
    auto [p, x] = pq.top();
    if (x == 0) {
      impossible = false;
      cout << Y[j] << endl;
      break;
    }
    pq.pop();
  }
  if (impossible) cout << "unknown" << endl;
  return 0;
}
