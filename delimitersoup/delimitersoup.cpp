#include <bits/stdc++.h>
using namespace std;

bool check(const string &line) {
  stack<char> S;
  for (size_t i = 0; i < line.size(); ++i) {
    char a, c = line[i];
    if (c == ' ') continue;
    switch (c) {
      case '(':
      case '[':
      case '{':
        S.push(c);
        break;
      default:
        if (c == ')') a = '(';
        else if (c == ']') a = '[';
        else if (c == '}') a = '{';
        if (S.empty() || S.top() != a) {
#ifdef DEBUG
          printf("%c vs %c\n", S.empty() ? 'X' : S.top(), c);
#endif
          printf("%c %lu\n", c, i);
          return false;
        }
        S.pop();
        break;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string line;
  getline(cin, line), getline(cin, line);
  if (check(line)) printf("ok so far\n");
  return 0;
}
