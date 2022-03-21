#include <bits/stdc++.h>
using namespace std;

using ti2 = tuple<int, int>;

bool possible(string &line, int s, int l) {
  string sub = line.substr(s, l);
  size_t a = line.find(sub);
  size_t b = line.find(sub, a + 1);
  return b != -1;
}

int solve(string &line) {
  queue<ti2> Q;
  int res = 1;
  for (size_t i = 0; i < line.size(); ++i) {
    Q.push(make_tuple(i, 1));
  }
  int s, l;
  while (!Q.empty()) {
    tie(s, l) = Q.front();
    Q.pop();
    res = max(res, l);
    if (possible(line, s, l)) {
      if (s + l < line.size()) Q.push(make_tuple(s, l + 1));
    } else return res - 1; 
  }
  return res -1;
}

int main() {
  string line;
  while (getline(cin, line)) {
    cout << solve(line) << endl;
  }
  return 0;
}
