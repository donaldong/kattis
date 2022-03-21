#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int res = 0, a = 0;
    for (int b = 1; b + 1 < s.size();) {
      if (s[a] == s[b + 1]) {
        a = b + 1;
        b += 2;
      } else {
        ++b, ++res;
      }
    }
    printf("%s\n", res % 2 == 0 ? "Bash" : "Chikapu");
  }

  return 0;
}
