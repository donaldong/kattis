/**
 * @date        2022-03-27
 * @tags        data structure, case work
 * @difficulty  1450
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N, K;
  unordered_set<string> completed;
  unordered_map<string,unordered_set<int>> H;
  unordered_set<int> seen;
  cin >> N >> K;
  while (K--) {
    int p1,p2;
    string c1,c2;
    cin >> p1 >> p2 >> c1 >> c2;
    if (c1 == c2) completed.insert(c1);
    else H[c1].insert(p1), H[c2].insert(p2);
    seen.insert(p1), seen.insert(p2);
  }
  if (H.size()+completed.size()>=N/2) {
#ifdef DEBUG
    printf("case 1\n");
#endif
    cout << (N/2-completed.size()) << endl;
    return 0;
  }
  int cnt = 0;
  for (auto& [c, s] : H) if (!completed.count(c) && s.size() >= 2) ++cnt;
#ifdef DEBUG
    printf("case 2: %d\n", cnt);
#endif
  if (seen.size()+2 == N && H.size()+completed.size()+1>=N/2) ++cnt;
  cout << cnt << endl;
  return 0;
}
