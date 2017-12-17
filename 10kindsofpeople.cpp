/**
 *  @brief   Kattis - 10 Kinds of People 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/23/2017
 *  
 *  + Grid
 *  + Disjoint Set
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

struct node {
    node *p = this;
    int r = 0;
};

node* find(node *n) {
    if (n->p != n)
        n->p = find(n->p);
    return n->p;
}

void u(node *a, node *b) {
    if (a->r > b->r) {
        b->p = a;
    } else if (a->r < b->r) {
        a->p = b;
    } else {
        b->p = a;
        ++a->r;
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> g(r);
    for (auto &r : g) cin >> r;
    vector<vector<node>> N(r);
    for (auto &v : N) {
        v = vector<node>(c);
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c - 1; ++j) {
            char c = g[i][j];
            char right = g[i][j+1];
            if (c == right) {
                auto p1 = find(&N[i][j]);
                auto p2 = find(&N[i][j+1]);
                if (p1 != p2) u(p1, p2);
            }
        }
    }
    for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < c; ++j) {
            char c = g[i][j];
            char down = g[i + 1][j];
            if (c == down) {
                auto p1 = find(&N[i][j]);
                auto p2 = find(&N[i + 1][j]);
                if (p1 != p2) u(p1, p2);
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1; --c1; --r2; --c2;
        auto p1 = find(&N[r1][c1]);
        auto p2 = find(&N[r2][c2]);
        if (p1 == p2) cout << (g[r1][c1] == '0' ? "binary" : "decimal") << endl;
        else cout << "neither" << endl;
    }
    return 0;
}
