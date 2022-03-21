#include <bits/stdc++.h>
using namespace std;

int MAX_STATES = 20;

using Tokens = vector<string>;
using State = vector<int>;
using States = vector<State>;

Tokens split(string &line, char c) {
  stringstream ss(line);
  string token;
  Tokens T;
  while (getline(ss, token, c)) {
    T.push_back(token);
  }
  return T;
}

void parse_token(string &s, int &n, bool &f) {
  f = false;
  size_t x = s.find('X');
  if (s.find('~') != -1) f = true;
  n = stoi(s.substr(x + 1, s.size() - x - 1)) - 1;
}

State parse_state(string &line, bool &t) {
  t = false;
  Tokens T = split(line, 'v');
  State M(MAX_STATES, -1);
  int n;
  bool f;
  for (auto &token : T) {
    parse_token(token, n, f);
    if (M[n] != -1 && M[n] != f) {
      t = true;
      break;
    }
    M[n] = f;
  }
  return M;
}

bool sat(State &S, int mark) {
  for (int i = 0; i < MAX_STATES; ++i, mark >>= 1) {
    if (S[i] == -1) continue;
    bool f = mark & 1;
    if (S[i]) f = !f;
    if (f) return true;
  }
  return false;
}

bool solve(int n, States &S) {
  for (int i = 0; i < 1 << n; ++i) {
    bool satisfied = true;
    for (auto s : S) {
      if (!sat(s, i)) {
        satisfied = false;
        break;
      }
    }
    if (satisfied) return true;
  }
  return false;
}

int main() {
  int t, n, m;
  string line;
  getline(cin, line);
  t = stoi(line);
  while (t--) {
    getline(cin, line);
    Tokens tokens = split(line, ' ');
    n = stoi(tokens[0]);
    m = stoi(tokens[1]);
    States S;
    while (m--) {
      getline(cin, line);
      bool t;
      auto state = parse_state(line, t);
      if (!t) S.push_back(state);
    }
    cout << (solve(n, S) ? "satisfiable" : "unsatisfiable") << endl;
  }
  return 0;
}
