#include <bits/stdc++.h>
using namespace std;
struct Node {
  array<Node*,26> children{nullptr};
  int cnt = 0;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int A, B;
  string name;
  Node root;
  cin >> A;
  while (A--) {
    cin >> name;
    auto cur = &root;
    for (char c : name) {
      auto& nxt = cur->children[c-'a'];
      if (!nxt) nxt = new Node();
      ++nxt->cnt;
      cur = nxt;
    }
  }
  cin >> B;
  while (B--) {
    cin >> name;
    auto cur = &root;
    for (char c : name) {
      auto& nxt = cur->children[c-'a'];
      cur = nxt;
      if (!cur) break;
    }
    cout << (cur? cur->cnt : 0) << endl;
  }
  return 0;
}
