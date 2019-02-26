#include <bits/stdc++.h>
using namespace std;

using hmap = unordered_map<string, int>;
using vs = vector<string>;
using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;

hmap ID;
vs N;
v2i E;
vb vis;
vi R;

int id(string &s) {
  if (ID.find(s) != ID.end()) return ID[s];
  int n = ID.size();
  ID[s] = n;
  N.push_back(s);
  E.push_back(vi());
  return n;
}

vs split(string &line) {
  stringstream ss(line);
  vs res;
  string tok;
  while (getline(ss, tok, ' ')) res.push_back(tok);
  return res;
}

void dfs(int a) {
  for (int b : E[a]) {
    if (vis[b]) continue;
    vis[b] = true;
    dfs(b);
  }
  R.push_back(a);
}

int main() {
  ios::sync_with_stdio(0);

  string line;
  int n;
  getline(cin, line);
  n = stoi(line);

  while (n--) {
    getline(cin, line);
    vs res = split(line);
    if (res.size() == 1) continue;
    res[0].pop_back();
    int a = id(res[0]);
    for (size_t i = 1; i < res.size(); ++i) {
      E[id(res[i])].emplace_back(a);
    }
  }

  R.reserve(N.size());
  vis.assign(N.size(), false);
  getline(cin, line);
  dfs(id(line));
  for (size_t i = R.size(); i-- > 0;) {
    printf("%s\n", N[R[i]].c_str());
  }
  return 0;
}
