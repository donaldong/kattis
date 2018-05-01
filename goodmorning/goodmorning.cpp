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

struct state {
    int v, r, c;
    int count = 1;
    state() {}
    state(int r, int c, int v) : r(r), c(c), v(v) {} 
};

int DR[] = {0, 0, 1};
int DC[] = {0, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> S;
    vector<vector<int>> G = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1,0, -1}
    };
    queue<state> Q;
    rep(i, 0, 4) rep(j, 0, 3) {
        if (G[i][j] != -1) {
            Q.push(state(i, j, G[i][j]));
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        S.insert(cur.v);
        Q.pop();
        rep(i, 0, 3) {
            int r = cur.r + DR[i];
            int c = cur.c + DC[i];
            if (r >= 0 && r < 4 && c >= 0 && c < 3) {
                if (G[r][c] != -1 && cur.count <= 2) {
                    state s(r, c, cur.v);
                    s.count = cur.count;
                    if (r != cur.r || c != cur.c) Q.push(s);
                    else if (r == cur.r && c == cur.c) {
                        state s2 = s;
                        s2.v *= 10;
                        s2.v += G[r][c];
                        ++s2.count;
                        if (s2.v <= 300) Q.push(s2);
                    }
                    s.v *= 10;
                    s.v += G[r][c];
                    ++s.count;
                    if (s.v <= 300) Q.push(s);
                }
            }
        }
    }
    int N;
    scan(N);
    while (N--) {
        int n;
        scan(n);
        auto itr = S.lower_bound(n);
        if (*itr == n) {
            cout << n << endl;
        } else {
            int b = *itr;
            int a = 0;
            if (itr != S.begin()) a = *(--itr);
            if (n - a > b - n) cout << b << endl;
            else cout << a << endl;
        }
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
