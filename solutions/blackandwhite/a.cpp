/**
 * @date        2022-03-22
 * @tags        dp, bitmask, math, probabilities
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
int N, LIM;
vector<double> P, DP;
double solve() {
  for (int mask = 1; mask < LIM; ++mask) {
    int cnt = 0;
    for (int i = mask; i; i >>= 1) if (i&1) ++cnt;
    if (cnt <= 2) {
      DP[mask] = 0.0;
      continue;
    }
    double turns = 0.0, pContinue = 1.0, allW = 1.0, allB = 1.0;
    for (int i = 0, b = 1; i < N; ++i, b <<= 1) {
      if (!(mask&b)) continue;
      allW *= P[i], allB *= 1.0-P[i];
    }
    for (int i = 0, b = 1; i < N; ++i, b <<= 1) {
      if (!(mask&b)) continue;
      double pW = P[i], pB = 1.0-pW;
      double pOut = pW*allB/pB + pB*allW/pW;
      turns += pOut * DP[mask ^ b];
      pContinue -= pOut;
    }
    DP[mask] = (turns+1.0)/(1.0-pContinue);
  }
  return DP.back();
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  cin >> N;
  LIM= 1<<N;
  P.resize(N), DP.assign(LIM, 0.0);
  for (auto& p : P) cin >> p;
  cout << setprecision(12) << solve() << endl;
  return 0;
}
