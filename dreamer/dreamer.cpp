#include <bits/stdc++.h>
using namespace std;

string MAX_DATE = "99999999";
int DAYS[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int y) {
  return (y % 4 == 0 && y % 100) || (y % 400 == 0);
}

bool valid(const string &s) {
  int y = stoi(s.substr(0, 4));
  int m = stoi(s.substr(4, 2));
  int d = stoi(s.substr(6, 2));
  if (y < 2000 || !m || !d || m > 12) return false;
#ifdef DEBUG
  printf("%04d-%02d-%02d\n", y, m, d);
#endif
  if (m == 2) {
    if (leap(y)) return d <= 29;
    return d <= 28;
  }
  return d <= DAYS[m - 1];
}

int main() {
  ios::sync_with_stdio(0);

  int t, k;
  string line, s, min_date;
  getline(cin, line);
  t = stoi(line);

  while (t--) {
    getline(cin, line);
    s = "";
    for (char c : line) if ('0' <= c && c <= '9') s += c;
    k = 0, min_date = MAX_DATE;
    sort(s.begin(), s.end());
    do {
      if (valid(s)) ++k, min_date = min(min_date, s);
    } while (next_permutation(s.begin(), s.end()));
    if (!k) printf("0\n");
    else printf(
      "%d %s %s %s\n",
      k, min_date.substr(6, 2).c_str(),
      min_date.substr(4, 2).c_str(),
      min_date.substr(0, 4).c_str()
    );
  }
  return 0;
}
