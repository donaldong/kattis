/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Brute Force
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

struct pt {
    int val;
    int r, c;
    pt() {}
    pt(int r, int c) : r(r), c(c) {}
    pt(int r, int c, int val) : val(val), r(r), c(c) {}
};

int get_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return c - 'A' + 37;
}

void connect(vector<string> &G, pt &a, pt &b) {
    int r1 = min(a.r, b.r), r2 = max(a.r, b.r);
    int c1 = min(a.c, b.c), c2 = max(a.c, b.c);
    if (r1 == r2) {
        rep(i, c1 + 1, c2) {
            if (G[r1][i] == '.') G[r1][i] = '-';
            else if (G[r1][i] == '|') G[r1][i] = '+';
        }
    } else {
        rep(i, r1 + 1, r2) {
            if (G[i][c1] == '.') G[i][c1] = '|';
            else if (G[i][c1] == '-') G[i][c1] = '+';
        }
    }
}

void print(pt &p) {
    cout << "[" << p.r << ", " << p.c << "]";
}


void print(vector<string> &G) {
    for (auto &row : G) cout << row << endl;
    cout << endl;
}

void solve(vector<string> &G) {
    vector<pt> P;
    rep(i, 0, G.size()) {
        rep(j, 0, G[i].size()) {
            if (G[i][j] != '.')
                P.pb(pt(i, j, get_val(G[i][j])));
        }
    }
    sort(P.begin(), P.end(), [](pt &a, pt &b) {
        return a.val < b.val;
    });
    rep(i, 1, P.size()) {
        connect(G, P[i - 1], P[i]);    
    }
    print(G);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<string> G;
    while (getline(cin, line)) {
        if (line.empty()) { 
            solve(G);
            G.clear();
            continue;
        } else {
            G.pb(line);
        }
    }
    solve(G);
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
