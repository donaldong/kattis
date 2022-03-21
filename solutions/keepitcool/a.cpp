#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N,M,S,D;
  cin >>N>>M>>S>>D;
  vector<int> C(S), rank(S);
  for (int& c : C) cin >> c;
  for (int i = 0; i < S; ++i) rank[i]=i;
  sort(rank.begin(), rank.end(), [&](int a, int b) {
    return C[a]<C[b];
  });

  int tot = 0;
  vector<int> res(S, 0);
  for (int r : rank) {
    int d = min(D-C[r], N);
    N-=d, res[r]+=d;
    if(N<=0) break;
  }
  for (int i = 0; i < S; ++i) {
    if (res[i] == 0) tot += C[i];
  }

  if (tot < M) cout << "impossible" << endl;
  else {
    for (int r : res) cout << r << ' ';
    cout << endl;
  }
  return 0;
}
