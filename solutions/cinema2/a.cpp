/**
 * @author      Donald Dong
 * @date        2022-03-21
 * @tags        implementation
 * @difficulty  1100
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0); // Fast IO
  int N,M,v,i=0;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> v;
    if (v <= N) N-=v;
    else {
      cout << M-i << endl;
      return 0;
    }
  }
}
