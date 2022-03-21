/**
 *  @brief   Kattis - Curse the Darkness 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/24/2017
 *  
 *  + Geometry
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

int main() {
    int m;
    cin >> m;
    while (m--) {
        ld x, y;
        cin >> x >> y;
        int n;
        cin >> n;
        bool f = false;
        while (n--) {
            ld x1, y1;
            cin >> x1 >> y1;
            ld dx = x - x1;
            ld dy = y - y1;
            if (dx * dx + dy * dy <= 64.0) f = true;
        }
        cout << (f ? "light a candle" : "curse the darkness") << endl;
    }
    return 0;
}
