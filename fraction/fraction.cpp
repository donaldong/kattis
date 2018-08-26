#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

struct rat {
  int p, q;
  rat() : p(1), q(1) {}
  rat(int p, int q) {
    if (q < 0) {
      p *= -1;
      q *= -1;
    }
    int k = gcd(abs(p), q);
    this->p = p / k;
    this->q = q / k;
  }

  rat operator+(const rat &o) {
    return rat(
      p * o.q + o.p * q,
      q * o.q
    );
  }

  rat operator-(const rat &o) {
    return rat(
      p * o.q - o.p * q,
      q * o.q
    );
  }

  rat operator*(const rat &o) {
    return rat(
      p * o.p,
      q * o.q
    );
  }

  rat operator/(const rat &o) {
    return rat(
      p * o.q,
      q * o.p
    );
  }

  rat flip() {
    return rat(q, p);
  }
};

void display(rat n) {
  int cur = n.p / n.q;
  while (true) {
    cout << cur << " ";
    n = n - rat(cur, 1);
    if (!n.p) break;
    n = n.flip();
    cur = n.p / n.q;
  }
  cout << endl;
}

rat build(int n) {
  rat res(0, 1);
  vector<int> V(n);
  for (auto &v : V) cin >> v;
  for (int i = n - 1; i >= 0; --i) {
    res = res + rat(V[i], 1);
    res = res.flip();
  }
  return res.flip();
}


int main() {
  int n, m;
  cin >> n >> m;
  rat A = build(n);
  rat B = build(m);
  display(A + B);
  display(A - B);
  display(A * B);
  display(A / B);
  return 0;
}
