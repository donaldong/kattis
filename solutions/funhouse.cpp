/**
 *  @brief   Kattis - Fun House 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/14/2017
 *  
 *  + Implementation
 *  + Grid
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

void get_entry(vector<string> &g, int &r, int &c) {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] == '*') {
                r = i;
                c = j;
                return;
            }
        }
    }
}

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

bool next(int &r, int &c, int &dir, vector<string> &g) {
    if (dir == UP) {
        r--;
        while (g[r][c] == '.') r--;
    } else if (dir == RIGHT) {
        c++;
        while (g[r][c] == '.') c++;
    } else if (dir == DOWN) {
        r++;
        while (g[r][c] == '.') r++;
    } else {
        c--;
        while (g[r][c] == '.') c--;
    }
    if (g[r][c] == '\\') {
        if (dir == UP) dir = LEFT;
        else if (dir == RIGHT) dir = DOWN;
        else if (dir == DOWN) dir = RIGHT;
        else dir = UP;
        return true;
    }
    if (g[r][c] == '/') {
        if (dir == UP) dir = RIGHT;
        else if (dir == RIGHT) dir = UP;
        else if (dir == DOWN) dir = LEFT;
        else dir = DOWN;
        return true;
    }
    return false;
}

void solve(vector<string> &g) {
    int r, c;
    get_entry(g, r, c);
    int dir = UP;
    if (c == 0) dir = RIGHT;
    else if (r == 0) dir = DOWN;
    else if (c + 1 == g[0].size()) dir = LEFT;
    while (next(r, c, dir, g));
    g[r][c] = '&';
}

int main() {
    int w, l;
    int i = 1;
    while (cin >> w >> l) {
        if (!w && !l) break;
        vector<string> g(l);
        for (auto &r : g) cin >> r;
        solve(g);
        cout << "HOUSE " << i++ << endl;
        for (auto &r : g) cout << r << endl;
    }
    return 0;
}
