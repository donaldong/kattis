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

int N, M;

struct pt {
    int r, c;
    int step = 0;
    pt() {}
    pt(int r, int c) : r(r), c(c) {}
};

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    scan(N), scan(M);
    vector<string> G(N);
    for (string &row : G) getline(cin, row);
    vector<vector<int>> T(N, vector<int>(M, -1));
    queue<pt> Q;
    Q.push(pt(0, 0));
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        rep(i, 0, 4) {
            int s = G[cur.r][cur.c] - '0';
            int r = cur.r + DR[i] * s;
            int c = cur.c + DC[i] * s;
            if (0 <= r && r < N && 0 <= c && c < M) {
                if (T[r][c] == -1 || T[r][c] > cur.step + 1) {
                    pt p(r, c);
                    p.step = cur.step + 1;
                    T[r][c] = p.step;
                    Q.push(p);
                }
            }
        }
    }
    cout << T[N - 1][M - 1] << endl;
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
