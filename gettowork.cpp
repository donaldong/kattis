/**
 *  @brief   Kattis - Get to Work 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/19/2017
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

int solve(deque<int> &v) {
    if (!v.size()) return 0;
    int res = 0;
    sort(v.begin(), v.end());
    while (v.back() > 0) {
       int n = v.back() - 1;
       while (n--) {
           if (!v.size()) return res + 1;
            v.pop_front();
       }
       if (!v.size()) return res + 1;
       v.pop_back();
       if (!v.size()) return res + 1;
       res++;
    }
    return -1;
}

string solve(int n, hmap<int, deque<int>> &m) {
    string res = "";
    for (int i = 1; i <= n; i++) {
        int car = solve(m[i]);
        if (car < 0) return "IMPOSSIBLE";
        res += to_string(car) + " ";
    }
    return res;
}

int main() {
    int C;
    cin >> C;
    int c = 0;
    while (++c <= C) {
        int n, t, e;
        cin >> n >> t >> e;
        hmap<int, deque<int>> m;
        while (e--) {
            int h, p;
            cin >> h >> p;
            m[h].push_back(p);
        }
        m[t] = deque<int>();
        printf("Case #%d: %s\n", c, solve(n, m).c_str());
    }
    return 0;
}
