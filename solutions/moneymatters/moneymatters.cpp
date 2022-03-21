/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
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

struct node {
    node *p;
    int val, r;
};

node *find(node *n) {
    if (n->p != n) 
        n->p = find(n->p);
    return n->p;
}

void __union(node *a, node *b) {
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    scan(n); scan(m);
    vector<node> N(n);
    rep(i, 0, n) {
        scan(N[i].val);
        N[i].r = 0;
        N[i].p = &N[i];
    }
    while (m--) {
        int a, b;
        scan(a); scan(b);
        auto ra = find(&N[a]);
        auto rb = find(&N[b]);
        if (ra != rb) __union(ra, rb);
    }
    hmap<node*, int> M;
    rep(i, 0, n) {
        M[find(&N[i])] += N[i].val;
    }
    bool f = true;
    for (auto &entry : M) {
        if (entry.second != 0) {
            f = false;
            break;
        }
    }
    cout << (f? "POSSIBLE" : "IMPOSSIBLE") << endl;
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
