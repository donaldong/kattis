#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using vs = vector<string>;
using hmap = unordered_map<string, uint>;
using ull = unsigned long long;
using ti2 = tuple<uint, uint>;
using vti2 = vector<ti2>;

ull gcd(ull a, ull b) {
  if (!b) return a;
  return gcd(b, a % b);
}

struct rat {
  ull p = 1, q = 0;
  rat() {}
  rat(ull p, ull q) {
    ull k = gcd(p, q);
    if (k == 0) {
      this->p = 1;
      this->q = 0;
    } else {
      this->p = p / k;
      this->q = q / k;
    }
  }
  rat operator*(rat &r) {
    return rat(p * r.p, q * r.q);
  }
  bool operator<(rat &r) {
    if (!q) return false;
    if (!r.q) return true;
    return p * r.q < q * r.p;
  }
};

using vr = vector<rat>; 
using v2r = vector<vr>;

void print(v2r &G) {
  cout << endl;
  for (auto &row : G) {
    for (auto i : row) printf("%lld/%lld ", i.p, i.q);
    cout << endl;
  }
}


vti2 floyd(v2r &G) {
  vti2 P(G.size());
  size_t size = G.size();
  for (size_t k = 0; k < size; ++k) {
    for (size_t i = 0; i < size; ++i) {
      for (size_t j = 0; j < size; ++j) {
        rat new_cost = G[i][k] * G[k][j];
        if (new_cost < G[i][j]) G[i][j] = new_cost;
      }
    }
  }
  size_t r = 0;
  for (;r < size; ++r) {
    bool f = true;
    for (size_t c = 0; c < size; ++c) {
      if (G[r][c].q != 1) {
        f = false;
        break;
      }
    }
    if (f) break;
  }
  for (size_t c = 0; c < size; ++c) P[c] = make_tuple(G[r][c].p, c);
  sort(P.begin(), P.end());
  return P;
}

int main() {
  int n, v;
  while (cin >> n) {
    if (!n) break;
    vs N(n);
    hmap M;
    v2r G(n, vr(n));
    for (int i = 0; i < n; ++i) { cin >> N[i]; M[N[i]] = i; G[i][i] = rat(1, 1); }
    string a, b;
    char c;
    for (int i = 1; i < n; ++i) {
      cin >> a >> c >> v >> b;
      int x = M[a], y = M[b]; 
      G[x][y] = rat(v, 1);
      G[y][x] = rat(1, v);
    }
    auto P = floyd(G);
    bool f = true;
    uint k, val;
    for (auto &p : P) {
      if (!f) cout << " = ";
      f = false;
      tie(val, k) = p;
      cout << val << N[k];
    }
    cout << endl;
  }
  return 0;
}
