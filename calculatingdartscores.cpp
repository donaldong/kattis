/**
 *  @brief   Kattis - Calculating Dart Scores 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2018
 *  
 *  + Equation
 *  + Brute Force
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

void print_score(int a, int x) {
    if (a == 0) return;
    else if (a == 1) cout << "single ";
    else if (a == 2) cout << "double ";
    else if (a == 3) cout << "triple ";
    cout << x << endl;
}

void solve(bool &f, int &a, int &b, int &c, int d, int &x, int &y, int &z) {
    for (a = 0; a <= 3; ++a) for (b = 0; b <= 3; ++b) for (c = 0; c <= 3; ++c) {
        for (x = 1; x <= 20; ++x) for (y = 1; y <= 20; ++y) for (z = 1; z <= 20; ++z) {
            if (a * x + b * y + c *z == d) {
                f = true;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d, x, y, z;
    cin >> d;
    bool f = false;
    solve(f, a, b, c, d, x, y, z);
    if (!f) cout << "impossible" << endl;
    else {
        print_score(a, x);
        print_score(b, y);
        print_score(c, z);
    }
    return 0;
}
