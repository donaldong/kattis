/**
 * @date        2022-03-27
 * @tags        implementation
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int C,N,f;
  cin >> C >> N;
  vector<bool> F(C+1, true);
  while (N--) {
    cin >> f;
    F[f] = false;
  }
  vector<pair<int,int>> error, correct;
  for (int i = 1; i <= C;) {
    int s = i;
    while (i <= C && F[s] == F[i]) ++i;
    if (F[s]) correct.emplace_back(s,i-1);
    else error.emplace_back(s,i-1);
  }
  printf("Errors: ");
  for (int i = 0; i < error.size(); ++i) {
    auto [a,b] = error[i];
    if (i+1 == error.size()) printf(" and ");
    else if (i) printf(", ");
    if (a == b) printf("%d", a);
    else printf("%d-%d",a,b);
  }
  printf("\nCorrect: ");
  for (int i = 0; i < correct.size(); ++i) {
    auto [a,b] = correct[i];
    if (i+1 == correct.size()) printf(" and ");
    else if (i) printf(", ");
    if (a == b) printf("%d", a);
    else printf("%d-%d",a,b);
  }
  printf("\n");
  return 0;
}
