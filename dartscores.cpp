/**
 *  @brief   Kattis - Darts 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/20/2017
 *  
 *  + Coordinate
 *  + Floating Point Numbers
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

int solve(int x, int y) {
    int r = x * x + y * y;
    if (r > 200 * 200) return 0;
    if (r > 180 * 180) return 1;
    if (r > 160 * 160) return 2;
    if (r > 140 * 140) return 3;
    if (r > 120 * 120) return 4;
    if (r > 100 * 100) return 5;
    if (r > 80 * 80) return 6;
    if (r > 60 * 60) return 7;
    if (r > 40 * 40) return 8;
    if (r > 20 * 20) return 9;
    return 10;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int scores = 0;
        while (n--) {
            int x, y;
            cin >> x >> y;
            scores += solve(x, y);
        }
        cout << scores << endl;
    }
    return 0;
}
