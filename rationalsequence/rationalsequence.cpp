#include <bits/stdc++.h>
using namespace std;

void up(uint a, uint b, uint &p, uint &q) {
  if (a > b) {
    p = a - b;
    if (b > p) {
      q = b - p;
      q = p + q;
      return; // case 1
    }
    q = b;
    p = a - 2 * b;
    p = p + q;
    return; // case 2
  }
  p = a;
  if (b > 2 * p) {
    q = b - 2 * p;
    q = p + q;
    return; // case 3
  }
  q = b - a;
  p = a - q;
  p = p + q; // case 4
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  uint n, t, p, q, mask;
  cin >> n;
  string s, tok;
  for (uint i = 1; i <= n; ++i) {
    cin >> t >> s;
    stringstream ss(s);
    getline(ss, tok, '/'), p = stoi(tok);
    getline(ss, tok, '/'), q = stoi(tok);
    uint h = p / q;
    if (p != q) p %= q;
    else ++h;
    up(p, q, p, q);
#ifdef DEBUG
    printf("up to %u/%u, %d steps\n", p, q, h);
#endif
    p += q; // down right 1 
    q += h * p;
    printf("%u %u/%u\n", t, p, q);
  }
  return 0;
}
