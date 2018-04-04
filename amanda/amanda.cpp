/**
 *  @brief   Kattis - Amanda Lounges 
 *  @author  Donald Dong (@donaldong)
 *  @date    03/15/2018
 *  
 *  + BFS
 *  + Graph
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

struct node;

struct edge {
    node *a, *b;
    int w;
    edge() {}
    edge(node *a, node *b, int w) : a(a), b(b), w(w) {}
};

struct node {
    int v;
    bool f;
    vector<edge*> E;
    int r;
    node *p;
    node() {
        this->p = this;
        r = 0;
    }
};

node* find(node *n) {
    if (n->p != n) 
        n->p = find(n->p);
    return n->p;
}

void __union(node *a, node *b) {
    if (a->r > b->r) {
        b->p = a;
    } else if (b->r > a->r) {
        a->p = b;
    } else {
        b->p = a;
        ++a->r;
    }
}

bool possible(node *n, bool start, uint &res) {
    queue<edge*> Q;
    n->v = -1;
    for (auto e : n->E) Q.push(e);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (cur->b->v != -1) {
            cur->b->v = -1;
            cur->b->f = false;
            for (auto e : cur->b->E) Q.push(e);
        }
    }
    n->v = start;
    n->f = true;
    res = start;
    for (auto e : n->E) {
        if (e->w == 2) {
            if (n->v != -1 && n->v != 1) return false;
            n->v = 1;
        } else if (e->w == 0) {
            if (n->v != -1 && n->v != 0) return false;
            n->v = 0;
        }
        Q.push(e);
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (cur->b->v == -1) {
            if (cur->w == 2) {
                cur->b->v = 1;
            } else if (cur->w == 0) {
                cur->b->v = 0;
            } else {
                cur->b->v = 1 - cur->a->v;
            }
            if (cur->b->v == 1) ++res;
            if (!cur->b->f) {
                cur->b->f = true;
                for (auto e : cur->b->E) Q.push(e);
            }
        } else if (cur->w == 2) {
            if (cur->a->v != 1 || cur->b->v != 1) return false;
        } else if (cur->w == 0) {
            if (cur->a->v != 0 || cur->b->v != 0) return false;
        } else {
            if (cur->a->v + cur->b->v != 1) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    scan(N); scan(M);
    vector<node> T(N);
    while (M--) {
        int a, b, c;
        scan(a); scan(b); scan(c);
        --a; --b;
        T[a].E.pb(new edge(&T[a], &T[b], c));
        T[b].E.pb(new edge(&T[b], &T[a], c));
        auto ra = find(&T[a]);
        auto rb = find(&T[b]);
        if (ra != rb) __union(ra, rb);
    }
    uint res = 0;
    bool f = true;
    hset<node*> S;
    for (auto &n : T) {
        S.insert(find(&n));
    }
    for (auto n : S) {
        uint best = -1;
        uint r;
        if (possible(n, 0, r)) best = min(best, r);
        if (possible(n, 1, r)) best = min(best, r);
        if (best == -1) {
            f = false;
            break;
        }
        res += best;
    }
    if (!f) cout << "impossible" << endl;
    else cout << res << endl;
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
