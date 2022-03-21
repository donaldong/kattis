#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> P(n);
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    P[i] = {i+1,v};
  }
  auto itr = P.begin();
  while (P.size()>1) {
#ifdef DEBUG
    for (auto [i,v]: P) printf("(%d)%d ", i, v);
    cout << endl;
#endif
    int d = (distance(P.begin(), itr)+itr->second-1)%P.size();
    itr = P.begin()+d;
    itr = P.erase(itr);
    if (itr == P.end()) itr = P.begin();
  }
  cout << P[0].first << endl;
  return 0;
}
