/**
 *  @brief   Kattis - Prime Sieve 
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

int main() {
    ll n, q;
    cin >> n >> q;
    vector<bool> p(n + 1, true);
    p[1] = false;
    int c = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (!p[i]) continue;
        ++c;
        for (ll j = i * i; j <= n; j += i) {
            p[j] = false;
        }
    }
    for (ll i = n; i * i > n; --i) {
        if (p[i]) ++c;
    }
    cout << c << endl;
    while (q--) {
        int x;
        cin >> x;
        cout << p[x] << endl;
    }
    return 0;
}
