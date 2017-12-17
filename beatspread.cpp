/**
 *  @brief   Kattis - Beat the Spread! 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/26/2017
 *  
 *  + Numbers
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
#define mp make_pair

bool possible(int s, int d, int &a, int &b) {
    a = (s + d) / 2;
    b = s - a;
    if (a < 0 || b < 0) return false;
    if (abs(a - b) != d) return false;
    if (a < b) swap(a, b);
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        int a, b;
        if (possible(s, d, a, b)) {
            cout << a << " " << b << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}
