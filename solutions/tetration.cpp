/**
 *  @brief   Kattis - Tetration 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/16/2017
 *  
 *  + Binary Search
 *  + Exponential
 *  + Numbers
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

const ld step = 1e-6;
ld logn;

ld solve(ld beg, ld end, ld n) {
    ld mid = (beg + end) / 2;
    ld res = logn / log(mid);
    ld diff = n - res;
    if (n < 1) diff *= -1;
    if (abs(diff) < step) return mid;
    if (diff < 0) return solve(mid, end, n);
    return solve(beg, mid, n);
}

ld solve(ld n) {
    if (abs(n - 1.0) < step) return 1.0;
    logn = log(n);
    if (n < 1) return solve(0, 1, n);
    return solve(1, 3, n);
}

int main() {
    ld n;
    cin >> n;
    printf("%.6Lf\n", solve(n));
    return 0;
}
