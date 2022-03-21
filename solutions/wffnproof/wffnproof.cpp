#include <bits/stdc++.h>
using namespace std;

bool is_opt(char c) {
  return c == 'K' ||
    c == 'A' ||
    c == 'N' ||
    c == 'C' ||
    c == 'E';
}

bool is_var(char c) {
  return c == 'p' ||
    c == 'q' ||
    c == 'r' ||
    c == 's' ||
    c == 't';
}

string solve(string &str) {
  size_t N = 0;
  string vars, opts;
  for (char c : str) {
    if (c == 'N') ++N;
    else if (is_opt(c)) opts += c; 
    else if (is_var(c)) vars += c;
  }
  if (vars.empty()) return "no WFF possible";
  if (vars.size() > opts.size() + 1) vars = vars.substr(0, opts.size() + 1);
  else if (vars.size() <= opts.size()) opts = opts.substr(0, vars.size() - 1);
  return opts + string(N, 'N') + vars;
}

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "0") break;
    cout << solve(line) << endl;
  }
  return 0;
}
