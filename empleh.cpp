/**
 *  @brief   Kattis - Emag Eht Htiw Em Pleh 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/19/2017
 *  
 *  + Implementation
 *  + Chess
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

void setP(vector<string> &g, int r, int c, char p) {
    int offset_r = 1;
    int width_r = 2;
    int offset_c = 2;
    int width_c = 4;
    g[r * width_r + offset_r][c * width_c + offset_c] = p;
}

void put(vector<string> &g, string &s, bool white) {
    while (true) {
        int i = s.find(',');
        if (i == 3 || s.size() == 3) {
            char p = s[0];
            if (!white) p += -'A' + 'a';
            int r = 8 - (s[2] - '0');
            int c = s[1] - 'a';
            setP(g, r, c, p);
            if (s.size() == 3) return;
            s.erase(0, i + 1);
        } else if (i == 2 || s.size() == 2) {
            char p = white ? 'P' : 'p';
            int r = 8 - (s[1] - '0');
            int c = s[0] - 'a';
            setP(g, r, c, p);
            if (s.size() == 2) return;
            s.erase(0, i + 1);
        } else {
            return;
        }
    }
}

int main() {
    vector<string> g;
    g.push_back("+---+---+---+---+---+---+---+---+");
    g.push_back("|...|:::|...|:::|...|:::|...|:::|");
    g.push_back(g[0]);
    g.push_back("|:::|...|:::|...|:::|...|:::|...|");
    while (g.size() < 16) {
        for (int i = 0; i < 4; i++) {
            g.push_back(g[i]);
        }
    }
    g.push_back(g[0]);
    string s;
    cin >> s; cin >> s;
    put(g, s, true);
    cin >> s; cin >> s;
    put(g, s, false);
    for (string r : g) cout << r << endl;
    return 0;
}
