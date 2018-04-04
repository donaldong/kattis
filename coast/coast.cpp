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

hset<ull> points;

ull get_key(point p) {
    ull res = p.r;
    res <<= 32;
    return res + p.c;
}

point get_point(ull key) {
    point p;
    p.c = key;
    key >>= 32;
    p.r = key;
    return p;
}

point get_point() {
    return get_point(*points.begin());
}

void erase_point(point p) {
    ull key = get_key(p);
    auto itr = points.find(key);
    if (itr != points.end()) points.erase(itr);
}


bool valid(point &p) {
    return p.r >= 0 && p.c >= 0;
}

int DR[] = {0, 0, -1, 1};
int DC[] = {1, -1, 0, 0};

int remove(vector<string> &G, point start, char from, char to, char check) {
    int res = 0;
    point a = start, b = start;
    queue<point> Q;
    Q.push(start);
    G[start.r][start.c] = to;
    erase_point(start);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (cur.r < a.r) a.r = cur.r;
        if (cur.c < a.c) a.c = cur.c;
        if (cur.r > b.r) b.r = cur.r;
        if (cur.c > b.c) b.c = cur.c;
        rep(i, 0, 4) {
            int r = cur.r + DR[i];
            int c = cur.c + DC[i];
            if (r >= 0 && r < G.size() && c >= 0 && c < G[0].size()) {
                if (G[r][c] == from) {
                    G[r][c] = to;
                    point p(r, c);
                    Q.push(p);
                    erase_point(p);
                } else if (G[r][c] == check) ++res;
            }
        }
    }
    if (a.r == 0 || a.c == 0) return res;
    if (b.r + 1 == G.size() || b.c + 1 == G[0].size()) return res;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    rep(i, 0, n) {
        cin >> G[i];
        rep(j, 0, m) {
            if (G[i][j] == '0') points.insert(get_key(point(i, j)));
        }
    }
    int res = 0;
    while (!points.empty()) {
        res += remove(G, get_point(), '0', '2', '1');
    }
    for (auto c : G[0]) if (c == '1') ++res;
    for (auto c : G.back()) if (c == '1') ++res;
    rep(i, 0, n) {
        if (G[i][0] == '1') ++res;
        if (G[i][m - 1] == '1') ++res;
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
