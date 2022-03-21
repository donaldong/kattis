#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map
using vs = vector<string>;
using svs = stack<vs>;

hmap<string, vs> M;

bool is_opt(string &s) {
  return s == "union" ||
    s == "intersection" ||
    s == "difference";
}

void opt(svs &S, int i) {
  auto a = S.top(); S.pop();
  auto b = S.top(); S.pop();
  vs v(a.size() + b.size());
  vs::iterator end;
  if (i == 0) end = set_union(a.begin(), a.end(), b.begin(), b.end(), v.begin());
  else if (i == 1) end = set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
  else end = set_difference(a.begin(), a.end(), b.begin(), b.end(), v.begin());
  v.resize(end - v.begin());
  S.push(v);
}

int main() {
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    vs tokens;
    string s;
    while (ss >> s) tokens.push_back(s);
    if (tokens[0] == "group") {
      for (size_t i = 3; i < tokens.size(); ++i) {
        M[tokens[1]].push_back(tokens[i]);
      }
      sort(M[tokens[1]].begin(), M[tokens[1]].end());
    } else {
      svs S;
      for (auto itr = tokens.rbegin(); itr != tokens.rend(); ++itr) {
        if (*itr == "union") opt(S, 0);
        else if (*itr == "intersection") opt(S, 1);
        else if (*itr == "difference") opt(S, 2);
        else S.push(M[*itr]);
      }
      for (auto &s : S.top()) cout << s << " ";
      cout << endl;
    }
  }
  return 0;
}
