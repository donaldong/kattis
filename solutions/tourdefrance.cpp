/**
 *  @brief   Kattis - Tour de France 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/28/2017
 *  
 *  + Implementation
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
    int f, r;
    int F[10], R[10];
    ld D[100];
    while (cin >> f >> r) {
        if (!f) break;
        rep(i, 0, f) cin >> F[i];
        rep(i, 0, r) cin >> R[i];
        rep(i, 0, f) rep(j, 0, r) {
            D[i * r + j] = ld(R[j]) / F[i];
        }
        int size = f * r;
        sort(D, D + size);
        ld res = 0.0;
        rep(i, 1, size) {
            res = max(res, D[i] / D[i-1]);
        }
        printf("%.2Lf\n", res);
    }
    return 0;
}

