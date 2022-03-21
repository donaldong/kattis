/**
 *  @brief   Kattis - Immortal Porpoises 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Numbers
 *  + Matrix
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

const ll MOD = 1e9;

void multiply(ll F[2][2], ll M[2][2]) {
  ll x = ((F[0][0]*M[0][0]) % MOD + (F[0][1]*M[1][0]) % MOD) % MOD;
  ll y = ((F[0][0]*M[0][1]) % MOD + (F[0][1]*M[1][1]) % MOD) % MOD;
  ll z = ((F[1][0]*M[0][0]) % MOD + (F[1][1]*M[1][0]) % MOD) % MOD;
  ll w = ((F[1][0]*M[0][1]) % MOD + (F[1][1]*M[1][1]) % MOD) % MOD;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(ll F[2][2], ll n) {
  if (n == 0 || n == 1) return;
  ll M[2][2] = {{1,1},{1,0}};
  power(F, n/2);
  multiply(F, F);
  if (n % 2 != 0) multiply(F, M);
}

ll fib(ll n) {
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0) return 0;
  power(F, n-1);
  return F[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll k, n;
        cin >> k >> n;
        cout << k << " " << fib(n) << endl;
    }
    return 0;
}
