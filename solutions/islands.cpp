/**
 *  @brief   Kattis - Islands in the Data Stream 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/18/2017
 *  
 *  + Recursion
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

int solve(vector<int> &v) {
    int res = 0;
    bool island = false;
    int beg = 0, h = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        int e = v[i];
        if (e > 0) {
            if (!island) beg = i;
            island = true;
            h = min(h, e);
        } else if (island) {
            island = false;
            res++;
            for (int j = beg; j < i; j++) {
                v[j] -= h;
            }
            h = INT_MAX;
        }
    }
    if (!res) return res;
    return res + solve(v);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> v(12);
        for (int &e : v) cin >> e;
        cout << k << " " << solve(v) << endl;
    }
    return 0;
}
