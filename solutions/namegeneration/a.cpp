/**
 * @date        2022-05-09
 * @tags        constructive algorithm
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;

  string C;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
    C += c;
  }

  auto toName = [&](int i) -> string {
    i += 0+21+21*21; // aaa
    string res;
    int l = 0;
    while (i) {
      res += C[i%21], i /= 21;
      l++;
      if (l % 3 == 2) res += 'a';
    }
    return res;
  };

  for (int i = 0; i < N; ++i) {
    printf("%s\n", toName(i).c_str());
  }
  return 0;
}
