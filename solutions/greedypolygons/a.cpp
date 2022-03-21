#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) {
    int n,l,d,g;
    cin>>n>>l>>d>>g;
    d *= g;
    double res = 0.0;
    res += (l*n)*(l/(2.0*tan(M_PI/n)))/2.0;
    res += M_PI*d*d;
    res += d*l*n;
    cout << setprecision(12) << res << endl;
  }
  return 0;
}
