#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;

string to_ram(int n) {
  string res = to_string(n);
  while (res.size() < 3) res = "0" + res;
  return res;
}

bool opt(vi &reg, string &s, size_t &i, vs &G) {
  int o = s[0] - '0';
  if (o == 1) return false;
  int a = s[1] - '0', b = s[2] - '0';
  if (o == 2) {
    reg[a] = b;
  } else if (o == 3) {
    reg[a] += b;
    reg[a] %= 1000;
  } else if (o == 4) {
    reg[a] *= b;
    reg[a] %= 1000;
  } else if (o == 5) {
    reg[a] = reg[b];
  } else if (o == 6) {
    reg[a] += reg[b];
    reg[a] %= 1000;
  } else if (o == 7) {
    reg[a] *= reg[b];
    reg[a] %= 1000;
  } else if (o == 8) {
    reg[a] = stoi(G[reg[b]]);
  } else if (o == 9) {
    G[reg[b]] = to_ram(reg[a]);
  } else if (reg[b] != 0) {
    i = reg[a];
    return true;
  }
  ++i;
  return true;
}

int main() {
  vs G;
  string line;
  while (getline(cin, line)) G.push_back(line);
  vi reg(10, 0);
  size_t i = 0;
  int res = 0;
  while (i < G.size()) {
    ++res;
    if (!opt(reg, G[i], i, G)) break;
  }
  cout << res << endl;
  return 0;
}
