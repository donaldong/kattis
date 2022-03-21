/**
 *  @brief   Kattis - Exactly Eletrical 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/15/2017
 *  
 *  + Coordinate
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

bool possible(int a, int b, int c, int d, int t) {
    int dx = abs(a - c), dy = abs(b - d);
    int td = t - dx - dy;
    if (td < 0) return false;
    return td % 2 == 0;
}

int main() {
    int a, b, c, d, t;
    cin >> a >> b >> c >> d >> t;
    cout << (possible(a, b, c, d, t) ? "Y" : "N") << endl;
    return 0;
}
