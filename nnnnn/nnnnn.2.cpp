#include <bits/stdc++.h>
using namespace std;

bool cmp(int n, const string &s) {
#ifdef DEBUG
  printf("%d <= %d ? \n", n, stoi(s));
#endif
  return n <= stoi(s);
}

int main() {
  string line;
  getline(cin, line);

  int dig = to_string(line.size()).size(), l;
  int n = line.size() - dig;
#ifdef DEBUG
  printf("len(L): %lu, dig: %d, n: %d\n", line.size(), dig, n);
#endif
  if (cmp(n + 1, line.substr(0, dig))) ++n;
#ifdef DEBUG
  printf("len(L): %lu, dig: %d, n: %d\n", line.size(), dig, n);
#endif

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
