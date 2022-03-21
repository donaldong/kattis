#include <bits/stdc++.h>
using namespace std;

typedef unordered_set<char> hset;

bool win(hset &S, const string &P) {
  int i = 0;
  for (char c : P) {
    auto itr = S.find(c);
    if (itr != S.end()) S.erase(itr);
    else {
      ++i;
      if (i == 10) return false;
    }
    if (S.empty()) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  string word, P;
  getline(cin, word);
  getline(cin, P);
  hset S;
  for (char c : word) S.insert(c);
  printf("%s\n", win(S, P) ? "WIN" : "LOSE");
  return 0;
}
