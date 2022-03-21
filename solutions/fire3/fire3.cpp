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

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

vector<vector<uint>> build(const vector<string> &G, vector<vector<uint>> &res, point &start) {
     queue<point> Q;
     Q.push(start);
     res[start.r][start.c] = 1;
     while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        uint n = res[cur.r][cur.c] + 1;
        rep(i, 0, 4) {
            int r = cur.r + DR[i];
            int c = cur.c + DC[i];
            if (r >= 0 && r < G.size() && c >= 0 && c < G.back().size()) {
                if (res[r][c] > n && G[r][c] != '#') {
                    res[r][c] = n;
                    Q.push(point(r, c));
                }
            }
        }
     }
     return res;
}

bool border(int r, int c, int n, int m) {
    if (r == 0 || c == 0) return true;
    if (r == n - 1 || c == m - 1) return true;
    return false;
}

uint solve(const vector<string> &G, const vector<vector<uint>> &C, point &start) {
    if (border(start.r, start.c, G.size(), G.back().size())) return 1;
    vector<vector<uint>> res(G.size(), vector<uint>(G.back().size(), -1));
    queue<point> Q; 
    Q.push(start);
    res[start.r][start.c] = 1;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        rep(i, 0, 4) {
            int r = cur.r + DR[i];
            int c = cur.c + DC[i];
            if (r >= 0 && r < G.size() && c >= 0 && c < G.back().size()) {
                if (res[r][c] == -1 && G[r][c] != '#') {
                    res[r][c] = res[cur.r][cur.c] + 1;
                    if (res[r][c] < C[r][c]) {
                        if (border(r, c, G.size(), G.back().size())) 
                            return res[r][c];
                        Q.push(point(r, c));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    point J;
    vector<point> F;
    rep(i, 0, n) {
        cin >> G[i];
        rep(j, 0, m) {
            if (G[i][j] == 'J') J = point(i, j);
            if (G[i][j] == 'F') F.pb(point(i, j));
        }
    }
    vector<vector<uint>> steps(G.size(), vector<uint>(G.back().size(), -1)); 
    for (auto &p : F) build(G, steps, p);
    uint res = solve(G, steps, J);
    if (res == -1) cout << "IMPOSSIBLE" << endl;
    else cout << res << endl;
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
