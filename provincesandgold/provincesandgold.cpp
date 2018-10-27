#include <bits/stdc++.h>
using namespace std;

int buy_v(int n) {
  if (n >= 8) return 0;
  if (n >= 5) return 1;
  if (n >= 2) return 2;
  return -1;
}

int buy_t(int n) {
  if (n >= 6) return 0;
  if (n >= 3) return 1;
  return 2;
}

string get_v(int n) {
  if (n == 0) return "Province";
  if (n == 1) return "Duchy";
  return "Estate";
}

string get_t(int n) {
  if (n == 0) return "Gold";
  if (n == 1) return "Silver";
  return "Copper";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int g, s, c;
  cin >> g >> s >> c;
  int total = 3 * g + 2 * s + c;
  int v = buy_v(total), t = buy_t(total);
  if (v < 0) cout << get_t(t) << endl;
  else cout << get_v(v) << " or " << get_t(t) << endl;
  return 0;
}
