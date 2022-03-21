#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a,b,x,y;
  cin >>a>>b>>x>>y;
  a-=2,b-=2;
  cout << (a>=x&&b>=y) << endl;
  return 0;
}
