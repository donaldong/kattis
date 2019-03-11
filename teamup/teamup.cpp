#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;

vi L, AL; // level, actual level
v2i S, T; // class, skill, tree
v3i C; // class i, team j, player k

vi group(const vi &children, int k) {// combine k-th team in all children
  vi res;
  for (int c : children) {
    for (auto p : C[c][k]) res.push_back(p);
  }
  return res;
}

void build(int n) {
  if (T[n].empty()) {
    AL[n] = L[n];
    return;
  }
  size_t t = 1e9;
  for (int c : T[n]) {
#ifdef DEBUG
    printf("%d => %d\n", n, c);
#endif
    build(c);
    t = min(t, C[c].size());
    AL[n] += AL[c];
  }
  if (L[n] && AL[n] != L[n]) return; // missing classes with certain skill
#ifdef DEBUG
  printf("class %d can add %zu teams\n", n, t);
#endif
  for (int i = 0; i < t; ++i) {
    C[n].push_back(group(T[n], i));
  }
#ifdef DEBUG
  printf("class %d now has %zu teams\n", n, C[n].size());
#endif
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p, i, j, k;
  cin >> n >> m >> p;
  L.assign(m + 1, 0);
  AL = L;
  S.resize(n + 1), C.resize(m + 1), T.resize(m + 1);
  for (i = 1; i <= m; ++i) {
    cin >> L[i];
    for (k = 0; k < L[i]; ++k) {
      cin >> j;
      S[j].push_back(i); // skill j has class i
    }
  }
  for (i = 1; i <= p; ++i) {
    cin >> k;
    C[k].push_back({i}); // class k has player i as a one-member team 
  }
  for (i = 1; i <= n; ++i) { // build the class tree
    if (S[i].empty()) {
      printf("0\n"); // there exists a skill not covered by any classes. no thanks 
      return 0;
    }
    sort(S[i].begin(), S[i].end(), [](int a, int b) {
      if (L[a] == L[b]) return a < b;
      return L[a] > L[b];
    });
    T[0].push_back(S[i][0]);
    for (j = 1; j < S[i].size(); ++j) {
      T[S[i][j - 1]].push_back(S[i][j]);
    }
#ifdef DEBUG
    printf("%d:\n", i);
    for (j = 0; j < S[i].size(); ++j) {
      if (S[j].empty()) continue;
      printf(" %d", S[i][j]);
    }
    printf("\n");
#endif
  }
  for (i = 0; i <= m; ++i) {
    if (T[i].empty()) continue;
    sort(T[i].begin(), T[i].end());
    auto last = unique(T[i].begin(), T[i].end());
    T[i].erase(last, T[i].end());
  }
  build(0);
  printf("%zu\n", C[0].size());
  for (auto &team : C[0]) {
    printf("%zu", team.size());
    sort(team.begin(), team.end());
    for (int p : team) printf(" %d", p);
    printf("\n");
  }
  cout << flush;
  return 0;
}
