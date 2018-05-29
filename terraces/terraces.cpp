/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
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

int R, C;
vector<vector<int>> G;
vector<vector<bool>> F;

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

bool possible(int r, int c, int &count) {
    int h = G[r][c];
    bool f = true;
    count = 1;
    F[r][c] = true;
    queue<pair<int, int>> Q;
    Q.push(mp(r, c));
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        rep(i, 0, 4) {
            r = cur.first + DR[i];
            c = cur.second + DC[i];
            if (0 <= r && r < R && 0 <= c && c < C) {
                if (G[r][c] < h) f = false;
                if (G[r][c] != h || F[r][c]) continue;
                F[r][c] = true;
                ++count;
                Q.push(mp(r, c));
            }
        }
    }
    return f;
}

int solve() {
    int res = 0;
    rep(i, 0, R) rep(j, 0, C) {
        int count;
        if (!F[i][j]){
            if (possible(i, j, count)) res += count;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    scan(C); scan(R);
    G = vector<vector<int>>(R, vector<int>(C));
    F = vector<vector<bool>>(R, vector<bool>(C, false));
    rep(i, 0, R) rep(j, 0, C) {
        scan(G[i][j]);
    }
    cout << solve() << endl;
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
