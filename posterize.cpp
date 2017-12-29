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

#define rep(i, s, e) for (int i = s, fe__ = e; i < fe__; ++i)

const int N = 256;

struct pixel {
    int r, p;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int d, k;
    cin >> d >> k;
    vector<pixel> P(d);
    for (auto &p : P) cin >> p.r >> p.p;
    sort(P.begin(), P.end(), [](pixel &a, pixel &b) {
        return a.r < b.r;
    });

    return 0;
}
