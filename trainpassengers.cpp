/**
 *  @brief   Kattis - Train Passengers 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2018
 *  
 *  + Implementation
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
    int C, N;
    cin >> C >> N;
    bool f = true;
    ll c = 0;
    rep(i, 0, N) {
        int left, enter, stay;
        cin >> left >> enter >> stay;
        c -= left; 
        if (c < 0) f = false;
        c += enter;
        if (c > C) f = false;
        if (stay != 0 && c < C) f = false;
        if (i + 1 == N && stay != 0) f = false;
        if (!f) break;
    }
    if (c != 0) f = false;
    cout << (f ? "possible" : "impossible") << endl;
    return 0;
}
