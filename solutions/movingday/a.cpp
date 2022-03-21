#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long N,V,a,b,c, res=LLONG_MIN;
  cin >> N >> V;
  while (N--) {
    cin>>a>>b>>c;
    res=max(res, a*b*c-V);
  }
  cout<<res<<endl;
  return 0;
}
