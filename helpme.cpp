/**
 *  @brief   Kattis - Help Me With The Game 
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

char getP(vector<string> &g, int r, int c) {
    int offset_r = 1;
    int width_r = 2;
    int offset_c = 2;
    int width_c = 4;
    return g[r * width_r + offset_r][c * width_c + offset_c];
}

bool print(char c, hmap<char, vector<pair<int, int>>> &m, bool white, bool first=false, bool pawn=false) {
    bool res = false;
    if (m.find(c) != m.end()) {
        auto v = &m[c];
        if (white) {
            sort(v->begin(), v->end(), [](pair<int, int> a, pair<int, int> b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second < b.second;
            });
        } else {
            sort(v->begin(), v->end(), [](pair<int, int> a, pair<int, int> b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            });
        }
        if (!white) c += - 'a' + 'A';
        for (auto p : *v) {
            char col = 'a' + p.second;
            int row = 8 - p.first;
            if (!first) { 
                cout << ",";
                if (!pawn) cout << c;
                cout << col << row;
                res = true;
            } else {
                if (!pawn) cout << c;
                cout << col << row;
                first = false;
                res = true;
            }
        }
    }
    return res;
}

void print(hmap<char, vector<pair<int, int>>> &m, bool white) {
    if (white) cout << "White: ";
    else cout << "Black: ";
    char K = white ? 'K' : 'k';
    char Q = white ? 'Q' : 'q';
    char R = white ? 'R' : 'r';
    char B = white ? 'B' : 'b';
    char N = white ? 'N' : 'n';
    char P = white ? 'P' : 'p';
    bool first = true;
    first &= !print(K, m, white, first);
    first &= !print(Q, m, white, first);
    first &= !print(R, m, white, first);
    first &= !print(B, m, white, first);
    first &= !print(N, m, white, first);
    first &= !print(P, m, white, first, true);
    cout << endl;
}

int main() {
    vector<string> g;
    string line;
    while (cin >> line) {
        g.push_back(line);
    }
    hmap<char, vector<pair<int, int>>> white, black;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto p = getP(g, i, j);
            if (p >= 'A' && p <= 'Z') white[p].push_back(mp(i, j));
            else if (p >= 'a' && p <= 'z') black[p].push_back(mp(i, j));
        }
    }
    print(white, true);
    print(black, false);
    return 0;
}
