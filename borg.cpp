/**
 *  @brief   Kattis - Killing Aliens in a Borg Maze 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
 *  
 *  + Graph
 *  + BFS
 *  + Minimum Spanning Tree
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

vector<int> DX = {0, 0, 1, -1};
vector<int> DY = {1, -1, 0, 0};

struct node {
    int rank = 0;
    node *p = this;
    bool f;
    int r, c, s;
    node() {}
    node(int r, int c) : r(r), c(c) {}
};

struct edge {
    int w;
    node *src, *dest;
    edge() {}
    edge(int w, node *src, node *dest) : w(w), src(src), dest(dest) {}
};

void bfs(vector<vector<node*>> &G, node *src, vector<node*> &N) { 
    for (auto n : N) {
        n->f = false;
        n->s = 0;
    }
    queue<node*> q;
    q.push(src);
    src->f = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        rep(i, 0, 4) {
            int r = cur->r + DX[i], c = cur->c + DY[i];
            if (r < 0 || r >= G.size()) continue;
            if (c < 0 || c >= G[r].size()) continue;
            if (!G[r][c]) continue;
            auto next = G[r][c];
            if (next->f) continue;
            next->f = true;
            next->s = cur->s + 1;
            q.push(next);
        }
    }
}

node* find(node *n) {
    if (n->p != n)
        n->p = find(n->p);
    return n->p;
}

void u(node *a, node *b) {
    if (a->r > b->r) b->p = a;
    else if (a->r < b->r) a->p = b;
    else {
        b->p = a;
        ++a->r;
    }
}

int mst(vector<edge*> &E) {
    int res = 0;
    sort(E.begin(), E.end(), [](edge *a, edge *b) {
        return a->w < b->w;   
    });
    for (auto e : E) {
        auto pa = find(e->src);
        auto pb = find(e->dest);
        if (pa != pb) {
            u(pa, pb);
            res += e->w;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        cin.ignore();
        vector<vector<node*>> G(y);
        vector<node*> N, A;
        rep(i, 0, y) {
            string line;
            getline(cin, line);
            G[i] = vector<node*>(line.size(), 0);
            rep(j, 0, line.size()) {
                if (line[j] != '#') {
                    N.pb(new node(i, j));
                    G[i][j] = N.back();
                    if (line[j] != ' ') A.pb(N.back());
                }
            }
        }
        vector<edge*> E;
        rep(i, 0, A.size()) {
            auto a = A[i];
            bfs(G, a, N);
            rep(j, i + 1, A.size()) {
                auto b = A[j];
                E.pb(new edge(b->s, a, b));
            }
        }
        cout << mst(E) << endl;
        for (auto n : N) delete n;
        for (auto e : E) delete e;
    }
    return 0;
}
