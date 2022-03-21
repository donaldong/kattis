/**
 *  @brief   Kattis - Combination Lock 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Counting
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

int calc(int a, int b) {
    int res = (a - b) * 9;
    if (res < 0) res += 360;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, a, b, c;
    while (cin >> k >> a >> b >> c) {
        if (!k && !a && !b && !c) break;
        int res = 360 * 3;
        res += calc(k, a);
        res += calc(b, a);
        res += calc(b, c);
        cout << res << endl;
    }
    return 0;
}
