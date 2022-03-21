/**
 *  @brief   Kattis - QAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Huffman
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
    ld p, b;
    ull n;
    node() {}
    node(ld p, ld b, ull n) : p(p), b(b), n(n) {}
    node(node *c) {
        p = c->p * 2;
        b = c->b + 1;
        n = c->n / 2;
    }
    node(node *l, node *r) {
        p = l->p + r->p;
        b = 1.0 + (l->p * l->b + r->p * r->b) / p;
        n = 1;
    }
};

struct cmp {
    bool operator() (node *a, node *b) const {
        if (a->p != b->p) return a->p < b->p;
        if (a->n != b->n) return a->n > b->n;
        return ull(a) < ull(b);
    }
};

ld prob(vector<ld> &P, vector<int> F) {
    ld res = 1;
    rep(i, 0, 4) {
        res *= pow(P[i], F[i]);
    }
    return res;
}

node* build(set<node*, cmp> &Q) {
    while (Q.size() > 1) {
        auto a = *Q.begin();
        Q.erase(Q.begin());
        if (a->n > 1) {
            Q.insert(new node(a));
            if (a->n & 1) {
                auto b = new node(a->p, a->b, 1);
                Q.insert(b);
            }
        } else {
            auto b = *Q.begin();
            b->n--;
            if (b->n < 1) Q.erase(Q.begin());
            auto c = new node(b->p, b->b, 1);
            Q.insert(new node(a, c));
        }
    }
    return *Q.begin();
}

void print(set<node*, cmp> &Q) {
    ld res = 0;
    for (auto itr : Q) { 
        res += itr->p * itr->n;
        cout << itr->p << " " << itr->n << endl;
    }
    cout << "total: ";
    cout << res << endl;
}

ld calc(set<node*, cmp> &Q) {
    auto root = build(Q);
    return root->b;
}

int main() {
    vector<ull> fact(21, 1);
    rep(i, 2, 21) fact[i] = fact[i - 1] * i;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ld> P(4);
    rep(i, 0, 4) cin >> P[i];
    ld res = 0;
    set<node*, cmp> nodes;
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; a + b <= n; ++b) {
            for (int c = 0; a + b + c <= n; ++c) {
                int d = n - a - b - c;
                nodes.insert(new node(
                    prob(P, {a, b, c, d}), 0,
                    fact[n] / fact[a] / fact[b] / fact[c] / fact[d]
                ));
            }
        }
    }
    cout << calc(nodes) << endl;
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
