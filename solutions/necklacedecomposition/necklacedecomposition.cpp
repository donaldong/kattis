#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
string S;

bool valid(const string &B, const string &A) {
  return A <= B;
}

bool necklace(const string &S) {
  string s = S;
  while (true) {
    s = s.back() + s;
    s.pop_back();
    if (s == S) return true;
    if (s < S) return false;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> S;
    vs tok;
    for (size_t i = 0; i < S.size();) {
      string s;
      while (i < S.size() && S[i] == '0') s += '0', ++i;
      while (i < S.size() && S[i] == '1') s += '1', ++i;
      tok.push_back(s);
    }
    while (true) {
      bool f = false;
      for (auto i = tok.begin(); i != tok.end();) {
        auto j = i + 1;
        while (j != tok.end() && !valid(*i, *j)) {
          *i += *j;
          j = tok.erase(j);
        }
        i = j;
      }
      if (!f) for (auto i = tok.begin(); i != tok.end();) {
        auto j = i + 1;
        while (j != tok.end() && necklace(*i + *j)) {
          *i += *j;
          j = tok.erase(j);
        }
        i = j;
      }
      if (!f) break;
    }
    for (auto &s : tok) printf("(%s)", s.c_str());
    printf("\n");
  }
  return 0;
}
