#include <bits/stdc++.h>
using namespace std;

bool cmp(int n, const string &s) {
  return n <= stoi(s);
}

int main() {
  string line;
  getline(cin, line);

  int n = line.size(), l;
  for (int i = 0; i <= min(7, n); ++i) {
    if (cmp(n - i, line.substr(0, i + 1))) {
      n -= i;
      break;
    }
  }

  if (line[0] == '0') printf("0\n");
  else {
    int cur = 0;
    size_t i;
    for (i = 0; i < line.size(); ++i) {
      cur = cur * 10 + line[i] - '0';
      if (cur >= n) {
        l = cur / n;
        printf("%d", l);
        cur -= l * n;
        break;
      }
    }
    for (++i; i < line.size(); ++i) {
      cur = cur * 10 + line[i] - '0';
      l = cur / n;
      printf("%d", l);
      cur -= l * n;
    }
    printf("\n");
  }

  return 0;
}
