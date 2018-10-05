#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;

int N, STATES;

string mark(string &S, int s) {
  if (!s) return "0";
  string res;
  for (int i = 0; i < N; ++i) {
    if (s & 1) res += S[i];
    s >>= 1;
  }
  return res;
}

int restore(int a, int b, int j, string &line) {
  int i, res = 0;
  j >>= 1;
  for (i = 1 << (N - 1); i; i >>= 1) {
    if (a & i) {
      if (!(b & j)) res |= i;
      j >>= 1;
    }
  }
  res = (STATES - 1) & res;
  i = 1;
  for (j = 0; j < N; ++j, i <<= 1) {
    if (!(res & i)) continue;
    if (line[j] == '0') res ^= i;
    else break;
  }
  return res;
}

void debug(int k) {
  for (int i = 1 << (N - 1); i; i >>= 1) {
    cout << bool(k & i);
  }
  cout << endl;
}

vi next_states(string &line, int cur) {
  vi res;
  string sub = mark(line, cur);
  int t = stoi(sub), k;
  if (!t) return res;
  int states = 1 << to_string(t).size(); 
  for (int i = 1; i < states - 1; ++i) {
    string s = mark(sub, i);
    if (s.empty()) continue;
    k = stoi(s);
    if (k <= 1) continue;
    if (t % k == 0)  {
      printf("%d / %d = 0\n", t, k);
      k = restore(cur, i, states, line);
      cout << " " << mark(line, k) << " ";
      debug(k);
      res.push_back(k);
    }
  }
  return res;
}

vi resolve(string &line, int s, vi &P) {
  vi res;
  while (s != -1) {
    cout << mark(line, s) << ",";
    res.push_back(stoi(mark(line, s)));
    s = P[s];
  }
  cout << endl;
  reverse(res.begin(), res.end());
  return res;
}

vi solve(string &line) {
  N = line.size();
  STATES = 1 << line.size();
  int cur = STATES - 1;
  // Parents, States
  vi P(STATES, -1), S(STATES, 0);
  vi final_states = {cur};
  queue<tuple<int, int>> Q;
  Q.emplace(1, cur); S.back() = 1;
  int step, max_step = 1;
  while (!Q.empty()) {
    tie(step, cur) = Q.front(); Q.pop(); 
    auto new_states = next_states(line, cur);
    for (auto s : new_states) {
      printf("new state: %s, cur step: %d, %d \n", mark(line, s).c_str(), step, S[s]);
      if (S[s] > step) continue;
      S[s] = step + 1;
      if (step + 1 == max_step) {
        final_states.push_back(s);
      } else if (step + 1 > max_step) {
        final_states = {s};
        max_step = S[s];
      }
      if (P[s] == -1) P[s] = cur;
      else if (S[P[s]] + 1 < S[s]) P[s] = cur;
      else if (
        S[P[s]] + 1 == S[s] &&
        stoi(mark(line, cur)) < stoi(mark(line, s))
      ) P[s] = cur;
      Q.emplace(S[s], s);
      cout << step << " " << mark(line, cur) << " ";
      cout << S[s] << " " << mark(line, s) << endl;
    }
  }
  vector<vi> G(final_states.size());
  for (size_t i = 0; i < G.size(); ++i) {
    G[i] = resolve(line, final_states[i], P);
  }
  sort(G.begin(), G.end(), [](vi &a, vi &b) {
    for (size_t i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
  });
  return G[0];
}

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "0") break;
    auto S = solve(line);
    for (auto &s : S) cout << s << " ";
    cout << endl;
  }
  return 0;
}
