/**
 *  @brief   Kattis - Perket 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/17/2017
 *  
 *  + Brute Force
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

struct ingred {
    int s, b;
};

ull solve(vector<ingred> &v, int bits) {
    ull s = 1, b = 0;
    for (int i = 0; i < v.size(); i++) {
        if (bits & 1) {
            s *= v[i].s;
            b += v[i].b;
        }
        bits >>= 1;
    }
    if (s > b) return s - b;
    return b - s;
}

int main() {
    int n;
    cin >> n;
    vector<ingred> v(n);
    for (auto &e : v) {
        cin >> e.s >> e.b;
    }
    ull res = -1;
    int all = pow(2, n);
    for (int i = 1; i < all; i++) {
        res = min(res, solve(v, i));
    }
    cout << res << endl;
    return 0;
}

