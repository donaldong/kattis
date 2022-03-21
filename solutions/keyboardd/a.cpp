#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string A, B;
  getline(cin, A);
  getline(cin, B);
  unordered_set<char> s;
  for (int i = 0, j = 0; j < B.size();) {
    if (i >= A.size()) {
      s.insert(B[j++]);
      continue;
    }
#ifdef DEBUG
    printf("A[%d]==B[%d]? (%c == %c)\n",i,j,A[i],B[j]);
#endif
    if (A[i] == B[j]) {
      ++i, ++j;
      continue;
    }
    while (i > 0 && j < B.size() && A[i]!=B[j]) {
#ifdef DEBUG
    printf("A[%d]!=B[%d]? (%c == %c)\n",i,j,A[i],B[j]);
#endif
      s.insert(B[j++]);
    }
  }
  for (char c : s) cout << c;
  cout << endl;
  return 0;
}
