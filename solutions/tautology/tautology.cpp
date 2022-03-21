#include <bits/stdc++.h>
using namespace std;

bool operation(char c) {
  return c == 'N' ||
    c == 'K' ||
    c == 'A' ||
    c == 'C' ||
    c == 'E';
}

string fix(string &line) {
  stack<string> S;
  for (int i = line.size() - 1; i >= 0; --i) {
    string c(1, line[i]);
    if (operation(c[0])) {
      if (c == "N") {
        S.top() += c;
      } else {
        string a = S.top();
        S.pop();
        string b = S.top();
        S.pop();
        S.push(a + b + c);
      }
    } else {
      S.push(c);
    }
  }
  return S.top();
}

void operate(stack<bool> &S, char c) {
  if (c == 'N') {
    bool f = S.top();
    S.pop();
    S.push(!f);
  }
  if (c == 'K') {
    bool a = S.top();
    S.pop();
    bool b = S.top();
    S.pop();
    S.push(a && b);
  }
  if (c == 'A') {
    bool a = S.top();
    S.pop();
    bool b = S.top();
    S.pop();
    S.push(a || b);
  }
  if (c == 'C') {
    bool x = S.top();
    S.pop();
    bool w = S.top();
    S.pop();
    S.push(!w || x);
  }
  if (c == 'E') {
    bool x = S.top();
    S.pop();
    bool w = S.top();
    S.pop();
    S.push(!x == !w);
  }
}

bool eval(string &line, int s) {
  vector<bool> B(5);
  for (int i = 0; i < 5; ++i) {
    B[i] = s & 1;
    s >>= 1;
  }
  auto get = [B](char c) {
    if (c == 'p') return B[0];
    if (c == 'q') return B[1];
    if (c == 'r') return B[2];
    if (c == 's') return B[3];
    return B[4];
  };
  stack<bool> S;
  for (char c : line) {
    if (operation(c)) {
      operate(S, c);
    } else {
      S.push(get(c));
    }
  }
  return S.top();
}

bool tautology(string &line) {
  for (int i = 0; i < 32; ++i) {
    if (!eval(line, i)) return false;
  }
  return true;
}

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "0") break;
    line = fix(line);
    cout << (tautology(line) ? "tautology" : "not") << endl;
  }
  return 0;
}
