#include <bits/stdc++.h>
using namespace std;

bool is_opt(char c) {
  return c == 'K' ||
    c == 'A' ||
    c == 'N' ||
    c == 'C' ||
    c == 'E';
}

string to_postfix(string &str) {
  size_t N = 0;
  string vars, opts;
  for (char c : str) {
    if (c == 'N') ++N;
    else if (is_opt(c)) opts += c; 
    else vars += c;
  }
  if (vars.empty()) return vars;
  if (vars.size() > opts.size() + 1) vars = vars.substr(0, opts.size() + 1);
  if (!vars.empty() && vars.size() < opts.size()) opts = opts.substr(0, vars.size() - 1);
  N = min(N, vars.size());
  vars += string(N, 'N');
  return vars + opts;
}

string to_prefix(string s) {
  if (s.empty()) return "no WFF possible";
  stack<string> S;
  for (char c : s) {
    if (is_opt(c)) {
      if (c == 'N') {
        S.top() = string(1, 'N') + S.top();
      } else {
        string res(1, c);
        res += S.top(), S.pop();
        res += S.top(), S.pop();
        S.push(res);
      }
    } else {
      S.push(string(1, c));
    }
  }
  return S.top();
}

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "0") break;
    cout << to_prefix(to_postfix(line)) << endl;
  }
  return 0;
}
