/**
 *  @brief   Kattis - Posterize 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/28/2017
 *  
 *  + Dynamic Programming
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

struct pixel {
    int r, p;
};

const int N = 256;
ull SE[N][N];
ull DP[N][N][N];

ull solve(int d, int k, int v) {
    if (k < 0 || d < k) return -2;
    if (DP[d][k][v] != -1) {
        return DP[d][k][v];
    }
    ull val = solve(d - 1, k, v);
    rep(i, k - 1, v) {
        val = min(val, solve(d - 1, k - 1, i));
    }
    if (val < -2) val += SE[d][v];
    DP[d][k][v] = val;
    return val;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int d, k;
    cin >> d >> k;
    vector<pixel> P(d);
    for (auto &p : P) cin >> p.r >> p.p;
    sort(P.begin(), P.end(), [](pixel &a, pixel &b) {
        return a.r < b.r;
    });
    rep(i, 0, N) rep(j, 1, k) rep(v, 0, N) {
        DP[i][j][v] = -1;
    }
    rep(i, 0, d) rep(j, 0, N) {
        ll diff = P[i].r - j;
        SE[i][j] = diff * diff * P[i].p;
        DP[i][0][j] = SE[i][j];
    }
    rep(i, 1, d) rep(j, 0, N) {
        DP[i][0][j] += DP[i-1][0][j];
    }
    ull res = -1;
    rep(i, k - 1, N) {
        res = min(res, solve(d - 1, k - 1, i));
    }
    cout << res << endl;
    return 0;
}
