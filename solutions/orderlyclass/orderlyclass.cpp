#include <bits/stdc++.h>
using namespace std;

void fix(string &a, string &b, int &i, int &j) {
  while (i < a.size() && a[i] == b[i]) { ++i; }
  while (j >= 0 && a[j] == b[j]) { --j; }
}

bool possible(string &a, string &b, int i, int j) {
  while (i < j) {
    if (a[i] != b[j]) return false;
    ++i; --j;
  }
  return true;
}

void solve(string &a, string &b, int &i, int &j) {
  i = 0, j = a.size() - 1;
  while (true) {
    fix(a, b, i, j);
    if (i == a.size() || j < 0) return;
    if (i >= j || possible(a, b, i, j)) return;
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
  if (i >= j || i == a.size() || j < 0) {
    cout << 0 << endl;
  } else {
    int res = 
      count(a, b, i, j, true, false) +
      count(a, b, i, j, false, true) +
      count(a, b, i, j, true, true);
    if (res) res -= 2;
    cout << res << endl;
  }
  return 0;
}
