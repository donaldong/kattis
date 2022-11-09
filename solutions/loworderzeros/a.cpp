/**
 * @date        2022-09-30
 * @tags        math, number theory
 * @difficulty  1450
 */
#include <bits/stdc++.h>
using namespace std;

int pow2mod10(int n) {
  if (n == 0) return 1;
  --n;
  vector<int> res{2,4,8,6};
  return res[n%4];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int MAX_N = 1e6;
  int n;
  vector<int> factorial_without_2s5s(MAX_N+1, 1);
  vector<int> num_twos(MAX_N+1, 0);
  for (int i = 2; i <= MAX_N; ++i) {
    int v = i;
    auto& t = num_twos[i];
    t += num_twos[i-1];
    while (v % 2 == 0) {
      ++t;
      v /= 2;
    }
    while (v % 5 == 0) {
      --t;
      v /= 5;
    }
    factorial_without_2s5s[i] = (factorial_without_2s5s[i-1] * v) % 10;
  }
  while (cin >> n) {
    if (n == 0) break;
    cout << (factorial_without_2s5s[n] * pow2mod10(num_twos[n])) % 10 << endl;
  }
  return 0;
}
