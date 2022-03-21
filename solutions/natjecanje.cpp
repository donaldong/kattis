/**
 *  @brief   Kattis - Natjecanje 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/18/2017
 *  
 *  + Implementation
 *  + Brute Force
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
    int n, s, r;
    cin >> n >> s >> r;
    set<int> S, R;
    while (s--) {
        int e;
        cin >> e;
        S.insert(e);
    }
    while (r--) {
        int e;
        cin >> e;
        R.insert(e);
    }
    for (auto i = S.begin(); i != S.end();) {
        auto e = *i;
        auto itr = R.find(e - 1);
        if (itr != R.end()) {
            R.erase(itr);
            i = S.erase(S.find(e));
            continue;
        }
        itr = R.find(e + 1);
        if (itr != R.end()) {
            R.erase(itr);
            i = S.erase(S.find(e));
            continue;
        }
        i++;
    }
    cout << S.size() << endl;
    return 0;
}
