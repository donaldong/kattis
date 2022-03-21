/**
 *  @brief   Kattis - Jury Jeopardy 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/27/2017
 *  
 *  + Implementation
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

const int E = 0, S = 1, W = 2, N = 3;

ll getkey(int r, int c) {
    ll res = r;
    res <<= 32;
    return res + c;
}

void move(int &r, int &c, int dir) {
    if (dir == E) {
        c++;
    } else if (dir == S) {
        r++;
    } else if (dir == W) {
        c--;
    } else {
        r--;
    }
}

void step(int &r, int &c, int &dir, char x) {
    if (x == 'B') {
        dir += 2;
        dir %= 4;
    } else if (x == 'R') {
        dir++;
        dir %= 4;
    } else if (x == 'L') {
        dir--;
        if (dir < 0) dir += 4;
    }
    move(r, c, dir);
}

int main() {
    int t;
    cin >> t;
    cout << t << endl;
    while (t--) {
        string line;
        cin >> line;
        int dir = E;
        int MMR = INT_MAX;
        int MR = 0, MC = 0;
        int R = 0, C = 0;
        hset<ll> path;
        path.insert(0);
        for (char c : line) {
            step(R, C, dir, c);
            path.insert(getkey(R, C));
            MR = max(MR, R);
            MMR = min(MMR, R);
            MC = max(MC, C);
        }
        vector<string> g(MR - MMR + 1);
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j <= MC; ++j) {
                if (path.find(getkey(i + MMR, j)) != path.end()) {
                    g[i] += '.';
                } else {
                    g[i] += '#';
                }
            }
            g[i] += '#';
        }
        cout << g.size() + 2 << " " << MC + 2 << endl;
        string s;
        for (int i = 0; i <= MC + 1; ++i) s += '#';
        cout << s << endl;
        for (auto &r : g) cout << r << endl;
        cout << s << endl;
    }
    return 0;
}
