/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Segment Tree
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

struct node {
    bool v = false;
    int n = 0;
    int a, b;
    node *l = 0, *r = 0;
    node() {}
    node(int i) : a(i), b(i) {}
};

node* join(node *a, node *b) {
    if (!b) return a;
    node *c = new node();
    c->a = a->a;
    c->b = b->b;
    c->l = a;
    c->r = b;
    return c;
}

node* build(vector<node*> v) {
    while (v.size() > 1) {
        vector<node*> v2;
        for (int i = 0; i < v.size(); i += 2) {
            node *b = 0;
            if (i + 1 < v.size()) b = v[i + 1];
            v2.pb(join(v[i], b));
        }
        v = v2;
    }
    return v[0];
}

void update(node *n, int i, bool inc) {
    if (n->a <= i && i <= n->b) {
        if (inc) ++n->n;
        else --n->n;
        if (n->l) update(n->l, i, inc);
        if (n->r) update(n->r, i, inc);
    }
}

int query(node *n, int a, int b) {
    if (a <= n->a && n->b <= b) return n->n;
    int res = 0;
    if (a > n->b || b < n->a) return res;
    if (n->l) res += query(n->l, a, b);
    if (n->r) res += query(n->r, a, b);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    scan(n); scan(k);
    vector<node*> v(n);
    rep(i, 0, n) v[i] = new node(i);
    auto root = build(v);
    while (k--) {
        char cmd = getchar();
        int a, b;
        getchar();
        scan(a);
        --a;
        if (cmd == 'F') {
            v[a]->v = !v[a]->v;
            update(root, a, v[a]->v);
        } else {
            scan(b);
            --b;
            cout << query(root, a, b) << endl;
        }
    }
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
