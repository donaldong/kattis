#include <bits/stdc++.h>
using namespace std;

using dqi = deque<int>;

dqi parse(string &line) {
  dqi Q;
  stringstream ss(line.substr(1, line.size() - 2));
  string token;
  while (getline(ss, token, ',')) Q.push_back(stoi(token));
  return Q;
}

bool update(char cmd, dqi &Q, bool &rev) {
  if (cmd == 'R') {
    rev = !rev;
    return true;
  }
  if (Q.empty()) return false;
  if (!rev) Q.pop_front();
  else Q.pop_back();
  return true;
}

void print(dqi &Q, bool rev) {
  cout << '[';
  bool f = true;
  if (!rev) {
    for (auto q : Q) {
      if (!f) cout << ',';
      f = false;
      cout << q;
    }
  } else {
    for (auto itr = Q.rbegin(); itr != Q.rend(); ++itr) {
      if (!f) cout << ',';
      f = false;
      cout << *itr;
    }
  }
  cout << ']' << endl;
}

int main() {
  int t;
  string line;
  getline(cin, line);
  t = stoi(line);
  while (t--) {
    string cmd;
    getline(cin, cmd);
    getline(cin, line);
    getline(cin, line);
    bool rev = false, error = false;
    auto Q = parse(line);
    for (size_t i = 0; i < cmd.size(); ++i) { 
      if (!update(cmd[i], Q, rev)) {
        error = true;
        break;
      }
    }
    if (error) cout << "error" << endl;
    else print(Q, rev);
  }
  return 0;
}
