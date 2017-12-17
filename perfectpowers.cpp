/**
 *  @brief   Kattis - Perfect Pth Powers 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
 *  
 *  + Numbers
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define mp make_pair

hmap<ll, ll> primeFactors(ll n) {
    hmap<ll, ll> f;
    while (n % 2 == 0) {
        f[2]++;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            f[i]++;
            n = n/i;
        }
    }
    if (n > 2) f[n]++;
    return f;
}

ll solveOdd(ll n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll solve(ll n) {
    bool neg = n < 0;
    if (neg) n *= -1;
    auto f = primeFactors(n);
    ll b = f.begin()->second;
    for (auto &entry : f) {
        b = gcd(b, entry.second);
    }
    if (neg && b % 2 == 0) return solveOdd(b);
    return b;
}

int main() {
    ll X;
    while (cin >> X) {
        if (X == 0) break;
        cout << solve(X) << endl;
    }
    return 0;
}
