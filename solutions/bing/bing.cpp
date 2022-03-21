#include <bits/stdc++.h>
using namespace std;

struct node {
  int count;
  bool word;
  vector<node*> C;
  node() {
    C = vector<node*>(26, 0);
    count = 0;
    word = false;
  }
};

int insert(node *n, string &s, int k=0) {
  ++n->count;
  int i = s[k] - 'a', res;
  if (k + 1 == s.size()) {
    if (n->C[i]) {
      res = n->C[i]->count;
      ++n->C[i]->count;
      return res;
    }
    auto nn = new node();
    nn->word = true;
    ++nn->count;
    n->C[i] = nn;
    return 0;
  }
  if (!n->C[i]) n->C[i] = new node();
  return insert(n->C[i], s, k + 1);
}

int main() {
  int N;
  cin >> N;
  auto root = new node();
  while (N--) {
    string s;
    cin >> s;
    cout << insert(root, s) << endl;
  }
  return 0;
}
