/**
 * @date        2022-03-23
 * @tags        data structure, set, hash set
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,M;
  cin >> N >> M;
  string item;
  set<string> S;
  for (int i = 0; i < M; ++i) {
    cin >> item;
    S.insert(item);
  }
  for (int i = 1; i < N; ++i) {
    unordered_set<string> S2;
    for (int j  = 0; j < M; ++j) {
      cin >> item;
      S2.insert(item);
    }
    for (auto itr = S.begin(); itr != S.end();) {
      if (S2.count(*itr)) {
        ++itr;
        continue;
      } else {
        itr = S.erase(itr);
      }
    }
  }
  printf("%lu\n", S.size());
  for (auto& s : S) printf("%s\n", s.c_str());
  return 0;
}
