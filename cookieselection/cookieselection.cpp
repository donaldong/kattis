#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct median_heap {
  priority_queue<int> L; // max heap
  priority_queue<int, vi, greater<int>> R; // min heap
  void insert(int n) {
    if (L.empty() || n <= L.top()) L.push(n);
    else R.push(n);
    balance();
  }
  int query() {
    int res;
    if (L.size() == R.size()) {
      res = R.top(); R.pop();
    } else {
      res = L.top(); L.pop();
    }
    balance();
    return res;
  }
  void balance() {
    while (L.size() < R.size()) {
      L.push(R.top()); R.pop();
    }
    while (L.size() > R.size() + 1) {
      R.push(L.top()); L.pop();
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  string line;
  median_heap M;
  while (getline(cin, line)) {
    if (line[0] == '#') cout << M.query() << endl;
    else M.insert(stoi(line));
  }
  return 0;
}
