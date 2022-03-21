/**
 *  @brief   Kattis - Black Friday 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/24/2017
 *  
 *  + Implementation
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
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (m.find(t) != m.end()) m[t] = -1;
        else m[t] = i;
    }
    int res = -1;
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
        if (i->second != -1) {
            res = i->second;
            break;
        }
    }
    if (res == -1) cout << "none" << endl;
    else cout << res << endl;
    return 0;
}
