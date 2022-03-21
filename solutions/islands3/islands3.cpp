/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Grid
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

struct point {
    int r, c;
    point() {}
    point(int r, int c) : r(r), c(c) {}
};

bool valid(point &p, const vector<string> &G) {
    return p.r >= 0 && p.r < G.size() && p.c >= 0 && p.c < G.back().size();
}

point find(vector<string> &G) {
    rep(i, 0, G.size()) rep(j, 0, G[i].size()) {
        if (G[i][j] == 'L') return point(i, j);
    }
    return point(-1, -1);
}

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

void remove(vector<string> &G, point &start) {
    queue<point> Q;
    Q.push(start);
    G[start.r][start.c] = 'W';
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        rep(i, 0, 4) {
            point p(cur.r + DR[i], cur.c + DC[i]);
            if (valid(p, G) && G[p.r][p.c] != 'W') {
                Q.push(p);
                G[p.r][p.c] = 'W';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    for (string &row : G) cin >> row;
    int count = 0;
    while (true) {
        point start = find(G);
        if (!valid(start, G)) break;
        remove(G, start);
        ++count;
    }
    cout << count << endl;
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
