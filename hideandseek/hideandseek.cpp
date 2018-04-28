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

struct node;

struct edge {
    node *src, *dest;
    uint w;
    edge(node *a, node *b, int t) {
        this->w = t;
        src = a;
        dest = b;
    }
};

struct node {
    vector<edge*> E;
    int i;
    node() {}
};

struct state {
    int t;
    set<int> S;
    state() {}
    state(int t) : t(t) {}
};

string get_key(state &s) {
    string res;
    for (int n : s.S) res += n;
    return res;
}

hmap<string, int> STATES;

size_t solve(node *start, int t) {
    size_t best = 0;
    queue<pair<state, node*>> Q;
    state start_state(0);
    start_state.S.insert(start->i);
    Q.push(mp(start_state, start));
    while (!Q.empty()) {
        auto front = Q.front();
        Q.pop();
        auto cur = front.second;
        for (auto e : cur->E) {
            auto next = e->dest;
            auto w = front.first.t + e->w;
            if (w <= t) {
                auto new_state = front.first;
                new_state.S.insert(next->i);
                new_state.t = w;
                string key = get_key(new_state);
                if (STATES.find(key) != STATES.end() && STATES[key] <= w) continue;
                best = max(best, new_state.S.size());
                Q.push(mp(new_state, next));
            }
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    scan(M); scan(N);
    vector<node> nodes(M);
    rep(i, 0, M) nodes[i].i = i;
    rep(i, 0, M - 1) {
        int u, v, t;
        scan(u); scan(v); scan(t);
        nodes[u].E.pb(new edge(&nodes[u], &nodes[v], t));
        nodes[v].E.pb(new edge(&nodes[v], &nodes[u], t));
    }
    cout << solve(&nodes[0], N) - 1 << endl;
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
