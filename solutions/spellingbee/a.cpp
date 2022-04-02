/**
 * @date        2022-04-01
 * @tags        implementation
 * @difficulty  1350
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  string d,w;
  int n;
  cin >> d >> n;
  unordered_set<char> S;
  for (char c : d) S.insert(c);
  while (n--) {
    cin >> w;
    bool valid = true, seenCenter = false;
    for (char c : w) {
      if (c == d[0]) seenCenter = true;
      if (!S.count(c)) {
        valid = false;
        break;
      }
    }
    if (w.size()<4 || !seenCenter) valid = false;
    if (valid) cout << w << endl;
  }
  return 0;
}
