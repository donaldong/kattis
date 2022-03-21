/**
 *  @brief   Kattis - Bank Queue 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/22/2017
 *  
 *  + Greedy
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

int pop(map<int, vector<int>> &q, int upper) {
    auto beg = q.upper_bound(upper);
    auto ii = beg;
    if (ii == q.end()) return 0;
    auto jj = ii->second.begin();
    auto m = *jj;
    for (auto i = beg; i != q.end(); ++i) {
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            if (*j > m) {
                m = *j;
                ii = i;
                jj = j;
            }
        }
    }
    ii->second.erase(jj);
    if (ii->second.size() == 0) {
        q.erase(ii);
    }
    return m;
}

int main() {
    int N, T;
    cin >> N >> T;
    map<int, vector<int>> q;
    for (int i = 0; i < N; ++i) {
        int c, t;
        cin >> c >> t;
        q[t].push_back(c);
    }
    int res = 0;
    for (int i = T - 1; i >= 0; --i) {
        res += pop(q, i - 1);
        if (q.size() == 0) break;
    }
    cout << res << endl;
    return 0;
}
