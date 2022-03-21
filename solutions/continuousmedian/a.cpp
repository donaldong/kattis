#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long res = 0;
    priority_queue<int> L;
    priority_queue<int,vector<int>,greater<int>> R;
    while (n--) {
      int v;
      cin >> v;
      if (R.empty() || v<R.top()) L.push(v);
      else R.push(v);

      while (R.size()>L.size()) {
        L.push(R.top());
        R.pop();
      }

      while (L.size()-R.size()>1) {
        R.push(L.top());
        L.pop();
      }
#ifdef DEBUG
      printf("v=%d, L(%d)=%d, R(%d)=%d\n", v, L.size(), L.size()?L.top():-1, R.size(), R.size()?R.top():-1);
#endif

      if (L.size()>R.size()) res += L.top();
      else res += (L.top()+R.top())/2;
    }
    cout << res << endl;
  }
  return 0;
}
