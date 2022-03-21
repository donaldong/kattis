#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> D(n+1, 0), N(n);
  for (int& v : N) {
    cin >> v;
    --v;
    ++D[v];
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i <= n; ++i) {
    if (!D[i]) pq.push(i);
  }
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = pq.top();
    int j = N[i];
#ifdef DEBUG
    printf("j=%d, res[%d]=%d\n", j, i, res[i]);
#endif
    --D[j];
    pq.pop();
    if (D[j] == 0) pq.push(j);
  }
  D.assign(n+1, 0);
  vector<vector<int>> adj(n+1);
  for(int i = 0; i < n; ++i) {
    int u = res[i], v = N[i];
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++D[u], ++D[v];
  }
  pq = {};
  for (int i = 0; i <= n; ++i) {
    if (D[i] == 1) pq.push(i);
  }
  int k = 0;
  while (!pq.empty() && k < n) {
    int u = pq.top();
#ifdef DEBUG
      printf("%d:\n", u);
#endif
    if (u != res[k] || D[u] != 1) {
      cout << "Error" << endl;
      return 0;
    }
    --D[u];
    pq.pop();
    for (int v : adj[u]) {
      if (!D[v]) continue;
      --D[v];
#ifdef DEBUG
      printf("%d->%d\n", u, v);
#endif
      if (D[v] != 1) continue;
      if (N[k] != v) {
        cout << "Error" << endl;
        return 0;
      }
      pq.push(v);
    }
    ++k;
  }

  for (int i : res) printf("%d\n", i+1);
  return 0;
}
