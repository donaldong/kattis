/**
 *  @brief   Kattis - Ricochet Robots 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/23/2018
 *  
 *  + Brute Force
 *  + BFS
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

struct _pos {
    char r, c;
    _pos() {}
    _pos(char r, char c) : r(r), c(c) {}
};

struct _state {
    vector<_pos> P;
    vector<string> G;
    uint step = 0;
    bool moved = false, f = false, end = false;
    _state() {}
    _state(int n, int h) {
        P = vector<_pos>(n);
        G = vector<string>(h);
    }
};

ll getkey(_state &s) {
    ll res = 0;
    for (auto &p : s.P) {
        res <<= 4;
        res += p.r;
        res <<= 4;
        res += p.c;
    }
    return res;
}

vector<int> DR = {0, 0, -1, 1};
vector<int> DC = {-1, 1, 0, 0};

void print(vector<string> &G) {
    for (string &s : G) {
        cout << s << endl;
    }
    cout << endl;
}

_state step(_state *s, int i, int dir, _pos &t) {
    _state res;
    res.P = s->P;
    res.G = s->G;
    int r = res.P[i].r, c = res.P[i].c;
    char p = res.G[r][c];
    res.G[r][c] = '.';
    while (true) {
        int nr = r + DR[dir];
        int nc = c + DC[dir];
        if (nr < 0 || nr >= res.G.size()) break;
        if (nc < 0 || nc >= res.G[0].size()) break;
        if (res.G[nr][nc] != '.') break;
        r = nr; c = nc;
        res.moved = true;
    }
    res.G[r][c] = p;
    if (r == t.r && c == t.c && p == '1') res.end = true;
    res.P[i].r = r;
    res.P[i].c = c;
    return res;
}

uint solve(_state &s, int l, _pos &t) {
    hmap<ll, _state> m; 
    queue<_state*> q;
    ll key = getkey(s);
    m[key] = s;
    q.push(&m[key]);
    q.front()->f = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur->step >= l) continue;
        rep(i, 0, cur->P.size()) rep(j, 0, 4) {
            auto ns = step(cur, i, j, t);
            ll k = getkey(ns);
            if (m.find(k) == m.end()) m[k] = ns;
            int step = ns.moved ? cur->step + 1: cur->step;
            if (m[k].step == 0 || m[k].step > step) {
                m[k].step = step;
            }
            m[k].end = ns.end;
            if (m[k].end) return m[k].step;
            if (!m[k].f) {
                q.push(&m[k]);
                m[k].f = true;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w, h, l;
    cin >> n >> w >> h >> l;
    _state s(n, h);
    _pos t;
    rep(i, 0, h) {
        cin >> s.G[i];
        rep(j, 0, w) {
            int k = s.G[i][j] - '1';
            if (k <= 3 && k >= 0) {
                s.P[k] = _pos(i, j);
            }
            if (s.G[i][j] == 'X') {
                t = _pos(i, j);
                s.G[i][j] = '.';
            }
        }
    }
    uint res = solve(s, l, t);
    if (res == -1) cout << "NO SOLUTION" << endl;
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
