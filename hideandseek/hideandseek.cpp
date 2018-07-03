/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + DP 
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

int N, M;
int INF = 1 << 30;
int BAD = 1 << 29;

struct node;

struct edge {
    node *n;
    int t;

    edge() {}
    edge(node *n, int t) : n(n), t(t) {}
};

struct node {
    vector<edge*> E;
    int k = 0, i;
    vector<int> T;
    node() {}
};

void build(node *n) {
    for (auto e : n->E) {
        build(e->n);
        n->k += e->n->k + 1;
    }
}

void print(vector<int> &vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

int calc(node *n, vector<int> &list);

int solve(node *n, int k) {
    if (k == 0) return 0;
    if (k > n->k) return BAD;
    --k;
    if (n->T[k] != INF) return n->T[k];
    vector<int> C(n->E.size(), 0);
    //cout << "BEG n: " << n->i << endl;
    while (true) {
        C[0]++;
        rep(i, 0, C.size() - 1) {
            if (C[i] > n->E[i]->n->k + 1) {
                C[i] = 0;
                ++C[i + 1];
            }
        }
        //cout << "C: ";
        //print(C);
        if (C.back() > n->E.back()->n->k + 1) break;
        int j = 0;
        rep(i, 0, C.size()) j += C[i];
        --j;
        int res = calc(n, C);
        // printf("j: %d, val: %d\n", j, res);
        n->T[j] = min(n->T[j], res); 
    }
    //cout << "END n: " << n->i << endl;
    return n->T[k];
}

int initial_cost(node *n, vector<int> &list) {
    int count = 0;
    rep(i, 0, list.size()) if (list[i]) ++count;
    if (!count) return 0;
    if (count == 1) {
        rep(i, 0, list.size()) if (list[i])
            return n->E[i]->t;
    }
    int res = 0;
    bool f = true;
    rep(i, 0, list.size()) {
        if (!list[i]) continue;
        if (f) {
            f = false;
            res += n->E[i]->t;
        } else {
            res += 2 * n->E[i]->t;
        }
    }
    return res;
}

int calc(node *n, vector<int> &list) {
    int res = 0, count = 0;
    bool f = true;
    rep(i, 0, list.size()) {
        if (list[i]) ++count;
    }
    if (!count) return 0;
    //print(list);
    rep(i, 0, list.size()) {
        if (!list[i]) continue;
        int r = solve(n->E[i]->n, list[i] - 1); 
        if (r >= BAD) return BAD;
        if (count == 1) {
            res = r + n->E[i]->t;
            if (res > M) return BAD;
            else break;
        } else {
            if (f) {
                f = false;
                res = r + n->E[i]->t;
            } else {
                res += 2 * (r + n->E[i]->t);
            }
        }
        if (res > M) return BAD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    scan(N), scan(M);
    vector<node> nodes(N);
    rep(i, 0, N) nodes[i].i = i;
    rep(i, 0, N - 1) {
        int a, b, c;
        scan(a), scan(b), scan(c);
        nodes[a].E.pb(new edge(&nodes[b], c));
    }
    build(&nodes[0]);
    rep(i, 0, N) if (nodes[i].k) {
        nodes[i].T = vector<int>(nodes[i].k, INF);
        sort(nodes[i].E.begin(), nodes[i].E.end(), [](edge *a, edge *b) {
            return a->t > b->t;
        });
    }
    solve(&nodes[0], nodes[0].k);
    int res = 0;
    for (int i = nodes[0].k - 1; i >= 0; --i) {
        if (nodes[0].T[i] >= BAD) continue;
        res = i + 1;
        break;
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
