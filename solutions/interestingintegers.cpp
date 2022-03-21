/**
 *  @brief   Kattis - Interesting Integers 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/29/2017
 *  
 *  + Brute Force
 *  + Numbers
 *  + Extended Euclidean
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

const int N = 46;
ll F[N];

ll gcdExt(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExt(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

bool possible(size_t i, ll n, ll &x, ll &y) {
    ll a = F[i - 1], b = F[i];
    if (a > n || b > n) return false;
    gcdExt(a, b, x, y);
    x *= n;
    y *= n;
    if (x <= y) {
        ll k = (y - x) / (a + b);
        x += k * b;
        y -= k * a;
    } else {
        ll k = (x - y) / (a + b);
        x -= k * b;
        y += k * a;
    }
    if (x > y) {
        x -= b;
        y += a;
    }
    return x >= 1 && y >= 1;
}

void solve(ll n, ll &g1, ll &g2) {
    for (int i = N; i >= 2; --i) {
        ll x, y; 
        if (possible(i, n, x, y)) {
            g1 = x;
            g2 = y;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    F[0] = 0;
    F[1] = 1;
    rep(i, 2, N) {
        F[i] = F[i - 1] + F[i - 2];
    }
    int T;
    cin >> T;
    rep(t, 0, T) {
        int n;
        cin >> n;
        ll g1, g2;
        g1 = g2 = LLONG_MAX;
        solve(n, g1, g2);
        cout << g1 << " " << g2 << endl;
    }
    return 0;
}
