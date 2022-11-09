/**
 * @date        2022-10-14
 * @tags        implementation
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<bool> B(1001, false);
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    B[b] = true;
  }
  for (int i = 1; i <= 1000; ++i) {
    if (!B[i]) continue;
    int start = i;
    while (i+1 <= 1000 && B[i+1]) ++i;
    if (start == i) printf("%d ", i);
    else if (i ==  start +1) printf("%d %d ", start, i);
    else printf("%d-%d ", start, i);
  }
  return 0;
}
