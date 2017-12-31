/**
 *  @brief   Kattis - Snapper Chain (Hard) 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/29/2017
 *  
 *  + Brute Force
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

bool on(int n, int k) {
    int mask = pow(2, n) - 1;
    int r = k & mask;
    return r == mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    rep(t, 0, T) {
        int n, k;
        cin >> n >> k;
        cout << "Case #"<< t + 1 << ": ";
        cout << (on(n, k) ? "ON" : "OFF") << endl;
    }
    return 0;
}
