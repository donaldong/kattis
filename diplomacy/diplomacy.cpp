/**
 *  @brief   Kattis - Diplomacy 
 *  @author  Donald Dong (@donaldong)
 *  @date    03/06/2018
 *  
 *  + Graph
 *  + Disjoin Set
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

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

struct governor {
    int party;
    governor *p;
    int rank;
    vector<governor*> friends;
    hset<governor*> out;
    bool f;
};

governor *find(governor *n) {
    if (n->p != n) 
        n->p = find(n->p);
    return n->p;
}

void __union(governor *a, governor *b) {
    if (a->rank > b->rank) {
        b->p = a;
    } else if (b->rank > a->rank) {
        a->p = b;
    } else {
        b->p = a;
        ++a->rank;
    }
}

uint height(governor *n) {
    uint res = 0;
    queue<pair<governor*, uint>> Q;
    Q.push(mp(n, 0));
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        cur.first->f = true;
        res = max(res, cur.second);
        for (auto g : cur.first->out) {
            if (!g->f) Q.push(mp(g, cur.second + 1));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    scan(N); scan(M);
    vector<governor> G(N);
    for (auto &g : G) {
        scan(g.party);
        g.p = &g;
        g.rank = 0;
    }
    while (M--) {
        int u, v;
        scan(u); scan(v);
        --u; --v;
        G[u].friends.pb(&G[v]);
        G[v].friends.pb(&G[u]);
        if (G[u].party == G[v].party) {
            auto ru = find(&G[u]);
            auto rv = find(&G[v]);
            if (ru != rv) __union(ru, rv);
        }
    }
    hset<governor*> groups;
    for (int i = 0; i < N; ++i) {
        auto rg = find(&G[i]);
        groups.insert(rg);
        for (auto f : G[i].friends) {
            auto rf = find(f);
            if (rf == rg) continue;
            rf->out.insert(rg);
            rg->out.insert(rf);
        }
    }
    uint res = -1;
    for (auto g : groups) {
        for (auto x : groups) x->f = false;
        uint h = height(g);
        res = min(res, h);
    }
    cout << res << endl;
    return 0;
}

inline void scan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void scan(ll &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void print(uint n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[11];
    int i = 10;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 10) putchar(buf[++i]);
}

inline void print(ull n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[20];
    int i = 19;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 19) putchar(buf[++i]);
}

inline void print(string &s) {
    rep(i, 0, s.length()) putchar(s[i]);
}
