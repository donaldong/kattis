/**
 *  @brief   Kattis - Need for Speed 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
 *  
 *  + Equation
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

const ld D = 1e-8;

ld calc(vector<ld> &s, vector<ld> &v, ld c) {
    ld res = 0;
    rep(i, 0, s.size()) {
        res += s[i]/(v[i] + c);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<ld> S(n), V(n);
    ld minv = 1000;
    rep(i, 0, n) {
        cin >> S[i] >> V[i];
        minv = min(minv, V[i]);
    }
    ld lo = -minv, hi = 1e7;
    while (hi - lo > D) {
        ld mid = (hi + lo) / 2;
        ld t0 = calc(S, V, mid);
        if (t0 > t) lo = mid;
        else hi = mid;
    }
    printf("%.6Lf\n", (lo + hi) / 2);
    return 0;
}
