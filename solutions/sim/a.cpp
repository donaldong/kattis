#include <bits/stdc++.h>
using namespace std;
struct Node {
  Node* prev = nullptr;
  Node* next = nullptr;
  char c = 0;
  Node() = default;
  Node(char c) : c(c) {}
  void deleteNext() {
    if (!next) return;
    if (next->next) next->next->prev = this;
    next = next->next;
  }
  void insert(char v) {
    auto n = new Node(v);
    n->prev = this;
    n->next = next;
    next = n;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  string line;
  getline(cin, line);
  while (T--) {
    getline(cin, line);
    Node *head = new Node();
    Node *tail = head;
    auto curr = head;
    for (char c : line) {
      switch (c) {
      case '<': {
        if (curr->prev) {
          curr = curr->prev;
          curr->deleteNext();
          if (!curr->next) tail = curr;
        }
        break;
      }

      case '[': {
        curr = head;
        break;
      }

      case ']': {
        curr = tail;
        break;
      }

      default: {
        curr->insert(c);
        curr = curr->next;
        if (!curr->next) tail = curr;
        break;
      }
      }
    }
    for (curr = head->next; curr; curr = curr->next) {
      cout << curr->c;
    }
    cout << endl;
  }
  return 0;
}
