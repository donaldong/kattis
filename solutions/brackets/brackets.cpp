#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
string S;

bool possible() {
  vi fo(S.size(), -1), fc = fo, bo = fo, bc = fo;
  int o = 0, c = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '(') ++o;
    else ++c;
    if (c > o) break;
    fo[i] = o, fc[i] = c;
  }
  if (o == c) return true;
  o = 0, c = 0;
  for (int i = S.size(); i--;) {
    if (S[i] == '(') ++o;
    else ++c;
    if (o > c) break;
    bo[i] = o, bc[i] = c;
  }
  for (int i = 0; i < S.size(); ++i) {
    // 0 -> i - 1: num open, num close
    int o1 = i ? fo[i - 1] : 0, c1 = i ? fc[i - 1] : 0;
    if (o1 < 0 || c1 < 0) break;
    o = 0, c = 0;
    for (int j = i; j < S.size(); ++j) { // invert i -> j
      if (S[j] == '(') ++o;
      else ++c;
      if (c1 + o > o1 + c) break;
      // j + 1 -> end: num open, num close
      int o2 = 0, c2 = 0;
      if (j + 1 < S.size()) o2 = bo[j + 1], c2 = bc[j + 1];
      if (o2 < 0 || c2 < 0) continue;
#ifdef DEBUG
      printf("( x %d, ) x %d, rev[%d %d], ( x %d, ) x %d\n", o1, c1, i, j, o2, c2);
#endif
      if (o1 + c + o2 == c1 + o + c2) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  getline(cin, S);
  printf("%s\n", possible() ? "possible" : "impossible");
  return 0;
}
