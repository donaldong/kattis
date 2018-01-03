/**
 *  @brief   Kattis - So you want to be a 2^n-aire? 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2017
 *  
 *  + Probability
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

const ld D = 1e-4;

ld prize(ld n, ld t) {
    return pow(2, n) * pow(t, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ld t;
    while (cin >> n >> t) {
        if (n == 0) break;
        ld lo = 0, hi = n;
        while (hi - lo > D) {
            ld mid = (lo + hi) / 2;
            ld a = prize(mid, t);
            ld b = prize(mid + 1, t);
            if (a < b) lo = mid;
            else hi = mid;
        }
        printf("%.3Lf\n", prize(lo, t));
    }
    return 0;
}
