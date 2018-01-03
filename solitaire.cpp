/**
 *  @brief   Kattis - Peg Solitaire 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/02/2018
 *  
 *  + Grid
 *  + Recursion
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

struct state {
    string g;
    int o = INT_MAX, s = INT_MAX;
};

int R = 5, C = 9;
vector<int> DR = {0, 0, 1, -1};
vector<int> DC = {1, -1, 0, 0};

int at(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return -1;
    return r * C + c;
}


state solve(hmap<string, state> &m, state &s) {
    if (s.o < 2) return s;
    if (m.find(s.g) != m.end()) return m[s.g];
    state res;
    res = s;
    rep(r, 0, R) rep(c, 0, C) {
        if(s.g[at(r, c)] == 'o') {
            rep(i, 0, 4) {
                int j = at(r + DR[i], c + DC[i]);
                int k = at(r + 2 * DR[i], c + 2 * DC[i]);
                if (j < 0 || k < 0) continue;
                if (s.g[j] != 'o') continue;
                if (s.g[k] != '.') continue;
                state ns;
                ns.g = s.g;
                ns.o = s.o - 1;
                ns.s = s.s + 1;
                ns.g[at(r, c)] = ns.g[j] = '.';
                ns.g[k] = 'o';
                auto t = solve(m, ns);
                if (t.o == res.o && t.s < res.s) res = t;
                else if (t.o < res.o) res = t;
            }
        }
    }
    m[s.g] = res;
    return res;
}

state solve(string &g) {
    hmap<string, state> m;
    state s;
    s.g = g;
    s.o = 0;
    s.s = 0;
    for (char c : g) if (c == 'o') ++s.o;
    return solve(m, s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string g;
        rep(r, 0, R) {
            string line;
            cin >> line;
            g += line;
        }
        auto res = solve(g);
        cout << res.o << " " << res.s << endl;
    }
    return 0;
}
