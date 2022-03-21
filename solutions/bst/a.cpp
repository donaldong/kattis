#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dist(n, 0);
  set<int> tree;
  long long C = 0;
  while (n--) {
    int v;
    cin >> v;;
    --v;
    auto [i,_] = tree.insert(v);
    int c = 0;
    if (i != tree.begin()) {
      c = max(dist[*prev(i)]+1, c);
    }
    if (i != tree.end() && next(i) != tree.end()) {
      c = max(dist[*next(i)]+1, c);
    }
    dist[v] = c;
    C += c;
    cout << C << endl;
  }
  return 0;
}
