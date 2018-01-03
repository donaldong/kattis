/**
 *  @brief   Kattis - Mountain Biking 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Physics
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
    ld g;
    cin >> n >> g;
    vector<ld> V2(n);
    rep(i, 0, n) {
        ld d, theta;
        cin >> d >> theta;
        theta *= M_PI / 180;
        ld a = g * cos(theta);
        V2[i] = 2 * a * d;
    }
    for (int i = n - 2; i >= 0; --i) {
        V2[i] += V2[i + 1];
    }
    rep(i, 0, n) {
        printf("%.7Lf\n", sqrt(V2[i]));
    }
    return 0;
}
