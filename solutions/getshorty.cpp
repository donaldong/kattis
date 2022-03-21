/**
 *  @brief   Kattis - Get Shorty 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/23/2017
 *  
 *  + Graph
 *  + Shortest Path
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

struct node;

struct edge {
    node *src, *dest;
    ld w;
    edge() {}
    edge(node *src, node *dest, ld w)
        : src(src), dest(dest), w(w) {}
};

struct node {
    vector<edge> edges;
    bool f = false;
    ld v = 0.0;
};

ld solve(vector<node> &N, int a) {
    auto beg = &N[a];
    set<pair<ld, node*>> q;
    beg->v = 1.0;
    q.insert(mp(1.0, beg));
    while (!q.empty()) {
        auto p = --q.end();
        auto cur = p->second;
        cur->f = true;
        q.erase(p);
        for (auto e : cur->edges) {
            auto next = e.dest;
            if (next->f) continue;
            auto v = max(next->v, cur->v * e.w);
            if (v > next->v) {
                auto i = q.find(mp(next->v, next));
                if (i != q.end()) q.erase(i);
                next->v = v;
                q.insert(mp(v, next));
            }
        }
    }
    return N.back().v;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        vector<node> N(n);
        while (m--) {
            int x, y;
            ld r;
            cin >> x >> y >> r;
            N[x].edges.push_back(edge(&N[x], &N[y], r));
            N[y].edges.push_back(edge(&N[y], &N[x], r));
        }
        printf("%.4Lf\n", solve(N, 0));
    }
    return 0;
}
