#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct item {
  int i, p, h;
  bool operator<(const item &a) const {
    return h < a.h;
  }
};

bool by_price(const item &a, const item &b) {
  return a.p < b.p;
}

vector<item> A, B, _A, _B;

bool solve() {
  multiset<item> front, back;
  for (int i = 0, a = 0, b = 0; i < A.size();) {
    if (front.empty() && a < A.size()) front.insert(A[a]), ++a;
    for (; a < A.size() && A[a - 1].p == A[a].p; ++a) front.insert(A[a]);
    if (back.empty() && b < B.size()) back.insert(B[b]), ++b;
    for (; b < B.size() && B[b - 1].p == B[b].p; ++b) back.insert(B[b]);
    if (front.empty() || back.empty()) return false;
    if (front.size() < back.size()) {
      for (auto x = front.begin(); x != front.end();) {
        auto y = back.upper_bound({-1, -1, x->h});
        if (y == back.end()) return false;
        _A[i] = *x, _B[i] = *y; // match!
        x = front.erase(x), back.erase(y), ++i;
      }
    } else {
      for (auto y = back.begin(); y != back.end();) {
        auto x = front.lower_bound({-1, -1, y->h});
        if (x == front.begin()) return false;
        --x;
        _A[i] = *x, _B[i] = *y; // match!
        front.erase(x), y = back.erase(y), ++i;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  A.resize(n), B.resize(n);
  _A.resize(n), _B.resize(n);
  for (auto &e : B) cin >> e.p;
  for (auto &e : B) cin >> e.h;
  for (auto &e : A) cin >> e.p;
  for (auto &e : A) cin >> e.h;
  for (int i = 0; i < n; ++i) A[i].i = B[i].i = i;
  sort(A.begin(), A.end(), by_price);
  sort(B.begin(), B.end(), by_price);

  if (!solve()) printf("impossible\n");
  else {
    for (auto &b : _B) printf("%d ", b.i + 1);
    printf("\n");
    for (auto &a : _A) printf("%d ", a.i + 1);
    printf("\n");
  }
  return 0;
}
