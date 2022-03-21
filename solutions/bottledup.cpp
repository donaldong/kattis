/**
 *  @brief   Kattis - Bottled-Up Feelings 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2018
 *  
 *  + Equation
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = gcd_ext(b, a % b, x1, y1);
    y = x1 - a / b * y1;
    x = y1;
    return gcd;
}

bool solve(ll s, ll a, ll b, ll &x, ll &y) {
    ll gcd = gcd_ext(a, b, x, y);
    if (s % gcd) return false;
    s /= gcd;
    x *= s; y *= s;
    if (y < 0) {
        ll k = -y / a;
        if ((-y) % a) ++k;
        x -= k * b;
        y += k * a;
    } else {
        ll k = y / a;
        x += k * b;
        y -= k * a;
    }
    return x >= 0 && y >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll s, a, b, x, y;
    cin >> s >> a >> b;
    ll k = gcd(s, a);
    k = gcd(k, b);
    s /= k; a /= k; b /= k;
    if (solve(s, a, b, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
