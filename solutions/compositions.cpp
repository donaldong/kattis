/**
 *  @brief   Kattis - Compositions 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/29/2017
 *  
 *  + Counting
 *  + Dynamic Programming
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

ll solve(int n, int m, int k) {
    vector<ll> t(n + 1, 0);
    rep(i, 1, n + 1) {
        rep(j, 1, i) {
            int diff = i - j;
            if (diff % k != m) {
                t[i] += t[j];
            }
        }
        if (i % k != m) ++t[i];
    }
    return t[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int P;
    cin >> P;
    rep(p, 0, P) {
        int K, n, m, k;
        cin >> K >> n >> m >> k;
        cout << K << " ";
        cout << solve(n, m, k) << endl;
    }
    return 0;
}
