/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + DFS
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
    ld r;
    node *dest;
    edge() {}
    edge(ld r, node *dest) : r(r), dest(dest) {}
};

struct node {
    vector<edge*> E;
    bool f = false;
    node() {}
};

bool solve(node *n, bool f) {
   stack<pair<ld, node*>> S;
   S.push(mp(1.0, n));
   n->f = f;
   while (!S.empty()) {
        auto p = S.top();
        S.pop();
        auto cur = p.second;
        for (auto e : cur->E) {
            auto next = e->dest;
            if (next->f == f) {
                if (next == n && p.first * e->r > 1.0) {
                    return true;
                }
            } else {
                next->f = f;
                S.push(mp(p.first * e->r, next));
            }
        }
   }
   return false;
}

ld convert(string &s) {
    int i = s.find(':');
    int a = stoi(s.substr(0, i));
    s.erase(0, i + 1);
    int b = stoi(s);
    return ld(b) / a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n) {
        if (!n) break;
        hmap<string, node*> nodes;
        while (n--) {
            string name;
            cin >> name;
            nodes[name] = new node();
        }
        cin >> m;
        while (m--) {
            string a, b, t;
            cin >> a >> b >> t;
            ld r = convert(t);
            nodes[a]->E.pb(new edge(r, nodes[b]));
        }
        bool f = false, t = true;
        for (auto &entry : nodes) {
            if (solve(entry.second, t)) {
                f = true;
                break;
            }
            t = !t;
        }
        cout << (f? "Arbitrage" : "Ok") << endl;
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
