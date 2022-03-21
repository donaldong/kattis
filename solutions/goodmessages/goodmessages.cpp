#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  switch (c) {
    case 'a': case 'e': case 'i':
    case 'o': case 'u': case 'y':
    return true;
  }
  return false;
}

int encode(string &s, int o) {
  int vals[] = {0, 0};
  for (char &c : s) {
    c -= 'a';
    c = (c + o) % 26;
    c += 'a';
    vals[is_vowel(c)]++;
  }
  return vals[1] * 2 < vals[0]; // happy: 1
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int o, n;
  string s;
  cin >> o >> s >> n;
  int vals[] = {0, 0};
  while (n--) vals[encode(s, o)]++;
  printf("%s\n", vals[1] > vals[0] ? "Boris" : "Colleague");
  return 0;
}
