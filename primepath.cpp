/**
 *  @brief   Kattis - Prime Path 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
 *  
 *  + Funny
 *  + Numbers
 *  + Graph
 *  + BFS
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
    int v;
    vector<node*> neigh;
    bool f;
    bool p = true;
    uint s;
};

vector<node> N(9000);

void connect(node &n, string s) {
    int i = stoi(s);
    i -= 1000;
    if (!N[i].p) return;
    n.neigh.pb(&N[i]);
}

void solve(int a, int b) {
    queue<node*> q;
    q.push(&N[a]);
    q.front()->s = 0;
    while (!q.empty()) {
        auto cur = q.front();
        if (cur->v == b + 1000) return;
        q.pop();
        cur->f = true;
        for (auto n : cur->neigh) {
            if (n->f) continue;
            n->s = min(n->s, cur->s + 1);
            q.push(n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 0, N.size()) N[i].v = i + 1000;
    for (int i = 2; i * i <= 9999; ++i) {
        if (i >= 1000 && !N[i - 1000].p) continue;
        for (int j = i * i; j <= 9999; j += i) {
            if (j >= 1000) N[j - 1000].p = false;
        }
    }
    for (auto &n : N) {
        if (!n.p) continue;
        string s = to_string(n.v);
        rep(i, 0, s.size()) {
            string neigh = s;
            char beg = i == 0 ? '1' : '0';
            for (char c = beg; c <= '9'; ++c) {
                neigh[i] = c;
                connect(n, neigh);
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        a -= 1000; b -= 1000;
        rep(i, 0, N.size()) {
            N[i].f = false;
            N[i].s = -1;
        }
        solve(a, b);
        if (N[b].s == -1) cout << "Impossible" << endl;
        else cout << N[b].s << endl;
    }
    return 0;
}
