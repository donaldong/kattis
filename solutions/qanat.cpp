/**
 *  @brief   Kattis - Qanat 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
 *  
 *  + Geometry
 *  + Binary Search
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

const ld D = 1e-9;
ld K;

ld calc(ld a, ld c) {
    return (1.0 - K * K) * (a + c) / 2.0;
}

ld scale_cost(ld cost, ld x, ld a) {
    ld k = a / x;
    return cost * k * k;
}

ld delta_cost(ld a, ld b) {
    ld ak = a * K, bk = b * K;
    ld d =  ak + bk + b - a;
    return d * d / 4 - ak * ak / 2;
}

ld delta_cost(ld a, ld b, ld c) {
    ld ak = a * K, bk = b * K, ck = c * K;
    ld d1 = ak + bk + b - a, d2 = bk + ck + c - b;
    return d1 * d1 / 4 + d2 * d2 / 4 - ak * ak / 2 - bk * bk / 2;
}

ld cost(ld old, ld a) {
    ld b = calc(a, 1);
    return scale_cost(old, 1, a) + delta_cost(a, b, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    K = h; K /= w;
    vector<ld> f(n);
    f[0] = (1.0 - K * K) / 2.0;
    ld c = f[0] + K * f[0]; c = c * c / 4;
    if (n == 1) c += delta_cost(f[0], 1); 
    else c = scale_cost(c, f[0], 1);
    rep(i, 1, n) {
        ld lo = 0, hi = 1;
        ld mid;
        while (hi - lo > D) {
            mid = (hi + lo) / 2;
            ld a = cost(c, mid);
            ld b = cost(c, mid + D);
            if (a > b) lo = mid;
            else hi = mid;
        }
        f[i] = calc(mid, 1);
        c = scale_cost(c, 1, mid) + delta_cost(mid, f[i]);
        if (i + 1 != n) c = scale_cost(c, f[i], 1);
        else c += delta_cost(f[i], 1);
    }
    vector<ld> X(n);
    ld x = w;
    for (int i = n - 1; i >= 0; --i) {
        X[i] = x * f[i];
        x = X[i];
    }
    c *= w * w;
    printf("%.5Lf\n", c);
    rep(i, 0, X.size()) {
        if (i >= 10) break;
        printf("%.5Lf\n", X[i]);
    }
    return 0;
}
