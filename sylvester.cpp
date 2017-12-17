/**
 *  @brief   Kattis - Sylvester Construction 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/17/2017
 *  
 *  + Matrix
 *  + Recursion
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

int solve(int64_t n, int64_t r, int64_t c, bool p=true) {
    if (n == 1) {
        if (p) return 1;
        return -1;
    }
    int64_t nn = n/2;
    if (c >= nn && r >= nn) return solve(nn, r-nn, c-nn, !p);
    if (c >= nn) c -= nn;
    if (r >= nn) r -= nn;
    return solve(nn, r, c, p);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int64_t n, x, y;
        int w, h;
        cin >> n >> x >> y >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << solve(n, y + i, x + j) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
