/**
 *  @brief   Kattis - Simplicity 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
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
    vector<int> v(26, 0);
    char c;
    while (cin >> c) {
        ++v[c - 'a'];
    }
    sort(v.begin(), v.end());
    int res = 0;
    rep(i, 0, 24) {
        res += v[i];
    }
    cout << res << endl;
    return 0;
}
