/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + TAG
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

int INF = 1 << 30;

struct node {
    int hi = INF;
    bool f = false;
    vector<node*> neigh;
};

void connect(node *a, node *b) {
    a->neigh.pb(b);
    b->neigh.pb(a);
}

void bfs(node *root) {
    queue<node*> Q;
    for (auto n : root->neigh) {
        n->f = true;
        Q.push(n);
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto n : cur->neigh) {
            if (n->f) continue;
            n->f = true;
            n->hi = cur->hi + 1;
            Q.push(n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, H, L;
    scan(N); scan(H); scan(L);
    vector<node> nodes(N);
    node root;
    root.hi = 0;
    while (H--) {
        int k;
        scan(k);
        nodes[k].hi = 0;
        root.neigh.pb(&nodes[k]);
    }
    while (L--) {
        int a, b;
        scan(a); scan(b);
        connect(&nodes[a], &nodes[b]);
    }
    bfs(&root);
    int max_val = 0, max_idx;
    rep(i, 0, N) if (nodes[i].hi > max_val) {
        max_val = nodes[i].hi;
        max_idx = i;
    }
    cout << max_idx << endl;
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
