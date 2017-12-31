/**
 *  @brief   Kattis - Event Planning 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/29/2017
 *  
 *  + Greedy
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, B, H, W;
    cin >> N >> B >> H >> W;
    uint cost = -1;
    rep(i, 0, H) {
        int p;
        cin >> p;
        rep(j, 0, W) {
            int a;
            cin >> a;
            if (a >= N && p * N <= B) {
                cost = min(cost, uint(p * N));
            }
        }
    }
    if (cost == -1) {
        cout << "stay home" << endl;
    } else {
        cout << cost << endl;
    }
    return 0;
}
