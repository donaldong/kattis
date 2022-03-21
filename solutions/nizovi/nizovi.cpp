#include <bits/stdc++.h>
using namespace std;

struct node {
  string content;
  // Children
  vector<node*> C; 
  node() {}
  node(string &content) : content(content) {}
};

void tab(int t) {
  for (int i = 0; i < t; ++i) cout << ' ';
}

void print(node *n, int t=0) {
  tab(t);
  cout << '{' << endl;
  t += 2;
  for (int i = 0; i < n->C.size(); ++i) {
    auto c = n->C[i];
    if (i + 1 != n->C.size()) {
      if (c->C.empty() && !c->content.empty()) {
        tab(t);
        cout << c->content;
      } else {
        print(c, t);
      }
      cout << ',' << endl;
    } else {
      if (c->C.empty() && !c->content.empty()) {
        tab(t);
        cout << c->content;
      } else {
        print(c, t);
      }
      cout << endl;
    }
  }
  tab(t - 2);
  cout << '}';
}

int main() {
  string line;
  cin >> line;
  stack<node*> S;
  string content;
  for (char c : line) {
    if (c == '{') {
      auto n = new node();
      if (!S.empty()) S.top()->C.push_back(n);
      S.push(n);
    } else if (c == '}') {
      if (!content.empty()) S.top()->C.push_back(new node(content));
      content.clear();
      if (S.size() > 1) S.pop();
    } else if (c == ',') {
      if (!content.empty()) S.top()->C.push_back(new node(content));
      content.clear();
    } else {
      content += c;
    }
  }
  print(S.top());
  cout << endl;
  return 0;
}
