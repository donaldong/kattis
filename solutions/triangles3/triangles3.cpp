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

struct pt {
    int r, c;
    pt() {}
    pt(int r, int c) : r(r), c(c) {}
};

struct node {
   vector<bool> to = vector<bool>(6, false); 
   node() {}
};

int DR[] = {-1, -1, 0, 1, 1, 0};
int DC[] = {-1, 1, 1, 1, -1, -1};

int rev(int dir) {
    if (dir < 3) return dir + 3;
    return dir - 3;
}

pt step(int i, int j, int dir) {
    if (i & 1) {
        if (dir == 0) return pt(i-1, j);
        if (dir == 1) return pt(i-1, j+1);
        if (dir == 2) return pt(i, j+1);
        if (dir == 3) return pt(i + 1, j+1);
        if (dir == 4) return pt(i + 1, j);
        return pt(i, j-1);
    }
    if (dir == 0) return pt(i-1, j-1);
    if (dir == 1) return pt(i-1, j);
    if (dir == 2) return pt(i, j+1);
    if (dir == 3) return pt(i + 1, j);
    if (dir == 4) return pt(i + 1, j-1);
    return pt(i, j-1);
}

void connect(vector<vector<node>> &N, int i, int j, int dir) {
    N[i][j].to[dir] = true;
    int rdir = rev(dir);
    auto p = step(i, j, dir);
    N[p.r][p.c].to[rdir] = true;
}

int solve(vector<vector<node>> &G) {

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    cin.ignore();
    string line;
    vector<string> G;
    while (getline(cin, line)) {
        G.pb(line);
    }
    vector<vector<node>> N(r, vector<node>(c));
    r = 0;
    rep(i, 0, G.size()) {
        bool f = true;
        c = 0;
        rep(j, 0, G[i].size()) {
            if (G[i][j] != 'x') continue;
            f = false;
            rep(dir, 0, 6) {
                int y = i + DR[dir];
                int x = j + DC[dir];
                if (y >= 0 && y < G.size() && x >= 0 && x < G[i].size()) {
                    if (G[y][x] != ' ') {
                        connect(N, r, c, dir);
                    }
                }
            }
            ++c;
        }
        if (!f) ++r;
    }
    cout << solve(N) << endl;
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
