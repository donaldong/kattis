/**
 *  @brief   Kattis - Reachable Roads 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/27/2017
 *  
 *  + Graph
 *  + Minimum Spanning Tree
 *  + Disjoint Set
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

struct node {
    int r;
    node *p;
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
    int t;
    cin >> t;
    vector<node> N(1000);
    while (t--) {
        int m, r;
        cin >> m >> r;
        for (size_t i = 0; i < m; ++i) {
            N[i].r = 0;
            N[i].p = &N[i];
        }
        while (r--) {
            int a, b;
            cin >> a >> b;
            auto pa = find(&N[a]);
            auto pb = find(&N[b]);
            if (pa != pb) u(pa, pb);
        }
        int res = 0;
        for (size_t i = 1; i < m; ++i) {
            auto pa = find(&N[0]);
            auto pb = find(&N[i]);
            if (pa != pb) {
                u(pa, pb);
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
