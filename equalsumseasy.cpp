/**
 *  @brief   Kattis - Equal Sums (Easy) 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/23/2017
 *  
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

int solve(vector<int> &v, int b, set<int> &s) {
    int res = 0;
    int i = 0;
    while (b) {
        if (b & 1) {
            res += v[i];
            s.insert(v[i]);
        }
        ++i;
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    int l = pow(2, 20);
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ":\n";
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &e : nums) cin >> e;
        hmap<int, vector<set<int>>> m;
        bool f = false;
        int sum;
        for (int i = 1; i < l; ++i) {
            set<int> s;
            sum = solve(nums, i, s);
            m[sum].push_back(s);
            if (m[sum].size() == 2) {
                f = true;
                break;
            }
        }
        if (!f) cout << "Impossible" << endl;
        else {
            for (auto s : m[sum]) {
                for (int e : s) {
                    cout << e << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
