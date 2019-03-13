#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

struct node {
  vector<node*> C;
  int diff = INT_MIN;
  node() : C(256, 0) {}
};

void build(node *p, const string &s, int d) {
  for (size_t i = 0; i < s.size(); ++i) {
    if (!p->C[s[i]]) p->C[s[i]] = new node();
    p = p->C[s[i]];
    p->diff = max(p->diff, d);
  }
}

int solve(node *p, const string &s) {
  int res = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    p = p->C[s[i]];
#ifdef DEBUG
    printf("%c diff(%d)\n", s[i], p->diff);
#endif
    if (!p->diff && !res) res = i + 1;
  }
  return p->diff <= 0 ? res : 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vs names(n);
  int t = 0;
  for (int i = 0; i < n; ++i) {
    cin >> names[i];
    if (names[i] == "ThoreHusfeldt") t = i;
  }
  if (t == 0) printf("Thore is awesome\n");
  else {
    node *root = new node();
    for (int i = 0; i < n; ++i) build(root, names[i], t - i);
    string prefix = "ThoreHusfeld";
    int res = solve(root, prefix);
    if (!res) printf("Thore sucks\n");
    else printf("%s\n", prefix.substr(0, res).c_str());
  }
  return 0;
}
