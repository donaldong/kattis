/**
 *  @brief   Kattis - Rot 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/21/2017
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

vector<string> rot45(vector<string> &g) {
    vector<string> res(g.size() + g.back().size() - 1);
    int r = 0;
    while (r < res.size()) {
        int i = min(r, (int)(g.size() - 1));
        int j = max(0, (int)(r - g.size() + 1));
        while (i >= 0 && j < g.back().size()) {
            res[r] += g[i--][j++];
        }
        r++;
    }
    return res;
}

vector<string> rot90(vector<string> &g) {
    vector<string> res(g.back().size());
    for (int i = g.size() - 1; i >= 0; --i) {
        for (int j = 0; j < g[i].size(); ++j) {
            res[j] += g[i][j];
        }
    }
    return res;
}

void display(vector<string> &g, int R) {
    for (string r : g) {
        int s = abs(--R);
        while (s--) cout << " ";
        for (int i = 0; i < r.size() - 1; ++i) {
            cout << r[i] << " ";
        }
        cout << r[r.size() - 1] << endl;
    }
}

void display(vector<string> &g) {
    for (auto &r : g) cout << r << endl;
}

void solve(vector<string> &g, int K) {
    if (K == 45) {
        auto res = rot45(g);
        display(res, g.size());
    } else if (K == 90) {
        auto res = rot90(g);
        display(res);
    } else if (K == 135) {
        auto res = rot90(g);
        res = rot45(res);
        display(res, g.back().size());
    } else if (K == 180) {
        auto res = rot90(g);
        res = rot90(res);
        display(res);
    } else if (K == 225) {
        auto res = rot90(g);
        res = rot90(res);
        res = rot45(res);
        display(res, g.size());
    } else if (K == 270) {
        auto res = rot90(g);
        res = rot90(res);
        res = rot90(res);
        display(res);
    } else if (K == 315) {
        auto res = rot90(g);
        res = rot90(res);
        res = rot90(res);
        res = rot45(res);
        display(res, g.back().size());
    } else {
        display(g);
    }
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    for (auto &r : g) cin >> r;
    int K;
    cin >> K;
    solve(g, K);
    return 0;
}
