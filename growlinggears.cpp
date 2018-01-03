/**
 *  @brief   Kattis - Growling Gears 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Equation
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

ld calc(int a, int b, int c) {
    ld x = b;
    x /= 2 * a;
    return a * x * x + b * x + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int igear = 0;
        ld vmax = 0;
        rep(i, 1, n + 1) {
            int a, b, c;
            cin >> a >> b >> c;
            ld res = calc(a, b, c);
            if (res > vmax) {
                vmax = res;
                igear = i;
            }
        }
        cout << igear << endl;
    }
    return 0;
}
