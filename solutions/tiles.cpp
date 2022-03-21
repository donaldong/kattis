/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + TAG
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

const int N = 50;
vector<int> V(N, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(w, 2, sqrt(N)) rep(h, 2, N / w) {
        cout << h - 1 << "!\n";
        rep(i, 1, h) rep(j, 1, w) {
            int x1 = j, y1 = 0, x2 = 0, y2 = i, x3 = w - j, y3 = h, x4 = w, y4 = h - i;
            int a = abs(x1 * y2 + x3 * y4 - x3 * y2 - x4 * y3 - x1 * y4) / 2;
            cout << a << endl;
        }
    }
    return 0;
}
