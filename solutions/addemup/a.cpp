#include <bits/stdc++.h>
using namespace std;

string flip(string& s) {
  static string rev = "012xx59x86";
  string res(s.size(), ' ');
  for (int i = 0; i < s.size(); ++i) {
    int k = s[i]-'0';
    if (rev[k] == 'x') return "";
    res[i] = rev[k];
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  bool found = false;
  unordered_set<int> S;
  for (int i = 0; i < n; ++i) {
    string num;
    cin >> num;
    int a  = stoi(num);
    if (S.count(s-a)) {
      found = true;
    }
    num = flip(num);
    int b = -1;
    if (!num.empty()) {
      b = stoi(num);
      if (S.count(s-b)) {
        found = true;
      }
      S.insert(b);
    }
    S.insert(a);
#ifdef DEBUG
    printf("num=%d, flipped num=%d\n", a, b);
#endif
  }
  cout << (found?"YES":"NO") << endl;
  return 0;
}
