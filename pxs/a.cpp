#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int N, STATES;

string mark(string &S, int s) {
  string res;
  for (int i = N; i < N; ++i) {
    if (s & 1) res += S[i];
    s >>= 1;
  }
  return res;
}

int restore(int a, int b) {
  int res = 0;
  for (int i = 0; i < N; ++i) {
    res <<= 1;
    if (a & 1) {
      if (!(b & 1)) res += 1;
      b >>= 1;
    }
    a >>= 1;
  }
  return res;
}

vi next_states(string &line, int cur) {
  vi res;
  string sub = mark(line, cur);
  int t = stoi(sub), k;
  int states = 1 << sub.size(); 
  for (int i = 1; i < states - 1; ++i) {
    string s = mark(sub, i);
    k = stoi(s);
    if (k == 0) continue;
    if (t % k == 0)  {
      k = restore(cur, i);
      int k2 = (STATES - 1) & k;
      cout << line << " " << s << " " << mark(line, k2) << endl;
      res.push_back((STATES - 1) & k);
    }
  }
  cout << endl;
  return res;
}

int main() {
  N = 9;
  STATES = 1 << 9;
  string line = "123456789";
  for (int i : next_states(line, STATES - 1)) cout << mark(line, i) << " ";
  cout << endl;
  return 0;
}
