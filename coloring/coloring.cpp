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

int X = 1;

struct node {
    int col = -1;
    bool f = false;
    vector<node*> neigh;
};

int pick_color(hset<int> &s) {
    int c = 1;
    while (true) {
        if (s.find(c) == s.end()) return c;
        ++c;
    }
    return c;
}

void solve(node *start,

void solve(node *start) {
    queue<node*> Q;
    Q.push(start);
    start->f = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        hset<int> col;
        for (auto n : cur->neigh) {
            col.insert(n->col);
            if (!n->f) {
                n->f = true;
                Q.push(n);
            }
        }
        cur->col = pick_color(col);
        X = max(X, cur->col);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scan(n);
    vector<node> N(n); 
    rep(i, 0, n) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int j;
        while (ss >> j) {
            N[i].neigh.pb(&N[j]);
        }
    }
    uint res = -1;
    rep(i, 0, n) {
        for (auto &e : N) {
            e.f = false;
            e.col = -1;
        }
        solve(&N[i]);
        res = min(res, uint(X));
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
