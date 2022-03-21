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

ull INF = -1;
int N;
vector<vector<ull>> M;

struct node {
    int i;
    int w;
    vector<node*> neigh;
    node* p;
};

ull solve(node *n, bool req) {
    if (M[n->i][req] != INF) return M[n->i][req];
    ull res;
    if (req) {
        res = n->w;
        for (auto c : n->neigh) {
           for (auto gc : c->neigh) {
               res += solve(gc, false);
           }
        }
        M[n->i][1] = res;
        return res;
    } else {
        ull sum = 0;
        for (auto c : n->neigh) sum += solve(c, false);
        res = INF;
        for (auto c : n->neigh) res = min(
            res,
            sum - solve(c, false) + solve(c, true)
        );
        res = min(res, solve(n, true));
        M[n->i][0] = res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    scan(N);
    vector<node> nodes(N);
    rep(i, 0, N) {
        nodes[i].i = i;
        scan(nodes[i].w);
        int k;
        scan(k);
        nodes[i].neigh = vector<node*>(k);
        rep(j, 0, k) {
            int n;
            scan(n);
            nodes[i].neigh[j] = &nodes[n];
            nodes[n].p = &nodes[i];
        }
    }
    node *root;
    rep(i, 0, N) {
        if (!nodes[i].p) {
            root = &nodes[i];
            break;
        }
    }
    M = vector<vector<ull>>(N, vector<ull>(2, INF));
    cout << solve(root, false) << endl;
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
