/**
 *  @brief   Kattis - George 
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
    int w;
    edge() {}
    edge(node *src, node *dest, int w) :
        src(src), dest(dest), w(w) {}
};

struct node {
    vector<edge> edges;
    int i;
    bool f;
    int v;
};

vector<node> N;
hmap<ll, int> G, T;

ll getkey(int x, int y) {
    int a, b;
    if (x < y) { a = x; b = y; }
    else { a = y; b = x; }
    ll res = a;
    res <<= 32;
    return res + b;
}

int solve(int a, int b, int k) {
    auto beg = &N[--a];
    beg->v = k;
    set<pair<int, node*>> q;
    q.insert(mp(k, beg));
    while (!q.empty()) {
        auto p = q.begin();
        auto cur = p->second;
        cur->f = true;
        q.erase(p);
        for (auto &e : cur->edges) {
            auto next = e.dest;
            if (next->f) continue;
            ll key = getkey(e.src->i, next->i);
            int value = cur->v;
            if (value < G[key] && value >= G[key] - T[key]) {
                value = G[key]; 
            }
            value = min(next->v, value + e.w);
            if (value < next->v) {
                auto i = q.find(mp(next->v, next));
                if (i != q.end()) q.erase(i);
                next->v = value;
                q.insert(mp(value, next));
            }
        }
    }
    return N[--b].v - k;
}

int main() {
    int n, m, a, b, k, g;
    cin >> n >> m >> a >> b >> k >> g;
    N = vector<node>(n);
    for (int i = 0; i < n; ++i) {
        N[i].v = INT_MAX;
        N[i].i = i;
        N[i].f = false;
    }
    int v;
    cin >> v;
    --v;
    vector<ll> keys(g - 1);
    for (int i = 0; i < g - 1; ++i) {
        int e;
        cin >> e;
        keys[i] = getkey(v, --e);
        v = e;
        G[keys[i]] = 0;
    }
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        N[x].edges.push_back(edge(&N[x], &N[y], w));
        N[y].edges.push_back(edge(&N[y], &N[x], w));
        ll key = getkey(x, y);
        if (G.find(key) != G.end()) { 
            G[key] = w;
            T[key] = w;
        }
    }
    for (int i = 1; i < keys.size(); ++i) {
        G[keys[i]] += G[keys[i - 1]];
    }
    cout << solve(a, b, k) << endl;
    return 0;
}
