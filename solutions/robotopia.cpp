/**
 *  @brief   Kattis - Robotopia 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/24/2017
 *  
 *  + Counting
 *  + Brute Force
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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac {
    ll p, q;
    frac(ll p, ll q) {
        ll d = gcd(abs(p), abs(q));
        if (q < 0) {
            q *= -1;
            p *= -1;
        }
        this->p = p / d;
        this->q = q / d;
    }

    bool equals(frac &f) {
        return p == f.p && q == f.q;
    }
};

frac add(frac &a, frac &b) {
    ll Q = a.q * b.q;
    ll p1 = a.p * b.q;
    ll p2 = b.p * a.q;
    return frac(p1 + p2, Q);
}

frac sub(frac &a, frac &b) {
    frac c(-b.p, b.q);
    return add(a, c);
}

frac div(frac &a, frac &b) {
    return frac(a.p * b.q, a.q * b.p);
}

frac mul(frac &a, frac &b) {
    return frac(a.p * b.p, a.q * b.q);
}

bool solve(frac &f1, frac &f2, int &x, int &y) {
    ll a = f1.p, b = f1.q, c = f2.p, d = f2.q;
    int X = 1;
    bool solved = false;
    ll up = a *d + c * b;
    ll down = b * d;
    while (up >= down) {
        if (up % down == 0) {
            if (solved) return false;
            y = up / down;
            x = X;
            solved = true;
        }
        X++;
        up += a * d;
    }
    return solved;
}

bool solve(int l1, int a1, int l2, int a2, int lt, int at, int &x, int &y) {
    int a = l1, b = l2, c = lt, d = a1, e = a2, f = at;
    frac k1(-a, b), k2(-d, e);
    frac b1(c, b), b2(f, e);
    if (k1.equals(k2)) return solve(k1, b1, x, y);
    frac p = sub(b2, b1), q = sub(k1, k2);
    frac X = div(p, q);
    if (X.q != 1 || X.p <= 0) return false;
    frac t = mul(X, k1);
    frac Y = add(b1, t);
    if (Y.q != 1 || Y.p <= 0) return false;
    x = X.p; y = Y.p;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l1, a1, l2, a2, lt, at;
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        int x, y;
        if (!solve(l1, a1, l2, a2, lt, at, x, y)) {
            cout << "?" << endl;
        } else {
            cout << x << " " << y << endl;
        }
    }
    return 0;
}

