/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Binary Search
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

struct node {
    int col = -1;
    vector<node*> neigh;
};

int X;

bool dfs(node *n) {
    vector<bool> C(X, false);
    for (auto e : n->neigh) {
        if (e->col != -1) {
            C[e->col] = true;
        }
    }
    rep(i, 0, C.size()) {
        if (C[i]) continue;
        n->col = i;
        bool f = true;
        for (auto next : n->neigh) {
            if (next->col != -1) continue;
            if (!dfs(next)) {
                f = false;
                next->col = -1;
                break;
            }
        }
        if (f) return true;
    }
    n->col = -1;
    return false;
}

bool colorable(vector<node> &N, int x) {
    X = x;
    rep(i, 0, N.size()) N[i].col = -1;
    return dfs(&N[0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node> N(n); 
    int max_degree = 0;
    cin.ignore();
    rep(i, 0, n) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int j;
        int d = 0;
        while (ss >> j) {
            N[i].neigh.pb(&N[j]);
            ++d;
        }
        max_degree = max(max_degree, d);
    }
    int lo = 1, hi = max_degree + 1;
    while (lo <= hi) {
        int col = (lo + hi) / 2;
        if (colorable(N, col)) hi = col - 1;
        else lo = col + 1;
    }
    cout << lo << endl;
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
