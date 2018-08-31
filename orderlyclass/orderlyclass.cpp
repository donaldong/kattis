#include <bits/stdc++.h>
using namespace std;

void fix(string &a, string &b, int &i, int &j) {
  while (!a.empty() && a[0] == b[0]) {
    a.erase(a.begin());
    b.erase(b.begin());
    ++i;
  }
  while (!a.empty() && a.back() == b.back()) {
    a.pop_back();
    b.pop_back();
    --j;
  }
}

void solve(string a, string b, int &i, int &j) {
  i = 0, j = a.size() - 1;
  while (true) {
    fix(a, b, i, j);
    if (a.empty()) return;
    reverse(b.begin(), b.end());
    if (a == b) return; 
    reverse(b.begin(), b.end());
    a.pop_back();
    b.pop_back();
    --j;
  }
}

int count(string &a, string &b, int i, int j, bool l, bool r) {
  int res = 0;
  int size = a.size();
  while (i >= 0 && j < size &&
      a[i] == b[j] && a[j] == b[i]) {
    if (l) --i;
    if (r) ++j;
    ++res;
  }
  return res;
}

int main() {
  string a, b;
  cin >> a >> b;
  int i, j;
  solve(a, b, i, j);
  if (i >= j) {
    cout << 0 << endl;
  } else {
    cout << 
      count(a, b, i, j, true, false) +
      count(a, b, i, j, false, true) +
      count(a, b, i, j, true, true) - 2
    << endl;
  }
  return 0;
}
