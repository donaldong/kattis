/**
 *  @brief   Kattis - So you want to be a 2^n-aire? 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2017
 *  
 *  + Probability
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ld t;
    while (cin >> n >> t) {
        if (n == 0) break;
        ld x = 0;
        ll prize = 1;
        ld q = 1.0 - t, p = 0.75;
        q = (0.5 - t) / q;
        if (q < 0) q = 0;
        ld r = (1.0 - q) * p;
        ld p_right = r, p_quit = q;
        rep(i, 0, n) {
            x = max(x, p_quit * prize + p_right * 2.0 * prize);
            prize *= 2;
            p_right *= r;
            p_quit *= r;
        }
        printf("%.3Lf\n", x);
    }
    return 0;
}
