#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, v;
  cin >> n;
  string s;
  deque<int> A, B;
  A.reserve(n), B.reserve(n);
  while (n--) {
    cin >> s >> v;
    if (s == "push_back") {
      B.push_back(v);
    } else if (s == "push_front") {
      A.push_front(v);
    } else if (s == "push_middle") {
      A.push_back(v);
    } else {
      if (v >= A.size()) printf("%d\n", B[v - A.size()]);
      else printf("%d\n", A[v]);
    }
    while (A.size() < B.size() + 1) A.push_back(B.front()), B.pop_front();
    while (B.size() + 1 < A.size()) B.push_front(A.back()), A.pop_back();
  }
  return 0;
}
