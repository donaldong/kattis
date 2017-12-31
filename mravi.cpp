/**
 *  @brief   Kattis - Mravi 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/29/2017
 *  
 *  + Graph
 *  + DFS
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

struct node {
    node *p;
    ld x;
    ld v = 0.0;
    bool t;
};

void solve(node *n) {
    if (!n->p) return;
    ld v = n->v;
    if (n->t) v = sqrt(v);
    v /= n->x / 100.0;
    n->p->v = max(n->p->v, v);
    solve(n->p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node> N(n);
    N[0].p = 0;
    rep(i, 1, n) {
        int a, b, x, t;
        cin >> a >> b >> x >> t;
        --a; --b;
        N[b].p = &N[a];
        N[b].x = x;
        N[b].t = t;
    }
    rep(i, 0, n) {
        int k;
        cin >> k;
        if (k != -1) {
            N[i].v = k;
            solve(&N[i]);
        }
    }
    printf("%.4Lf\n", N[0].v);
    return 0;
}
