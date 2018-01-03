/**
 *  @brief   Kattis - Euclidean TSP 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
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

const ld D = 1e-7;

ld calc(ld n, ld p, ld s, ld v, ld c) {
    ld d = log(n) / log(2);
    d = pow(d, c * sqrt(2));
    return n * d / (p * 1e9) + s * (1 + 1/c) / v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ld p, s, v;
    cin >> n >> p >> s >> v;
    ld lo = 0, hi = 1e9;
    while (hi - lo > D) {
        ld mid = (hi + lo) / 2;
        ld a = calc(n, p, s, v, mid);
        ld b = calc(n, p, s, v, mid + D);
        if (a > b) lo = mid;
        else hi = mid;
    }
    ld mid = (hi + lo) / 2;
    printf("%.7Lf %.7Lf\n", calc(n, p, s, v, mid), mid);
    return 0;
}
