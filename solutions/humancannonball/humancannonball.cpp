/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Shortest Path
 *  + Floyd
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
    ld x, y;
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
};

pt src, dest;
vector<pt> P;

pt get_pt(int i) {
    if (i < P.size()) return P[i];
    if (i == P.size()) return src;
    return dest; 
}

ld dist(pt &a, pt &b) {
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

ld calc(pt &a, pt &b, bool f) {
    ld d = dist(a, b);
    ld walk = d / 5.0;
    if (!f) return walk;
    ld fly = 2.0 + abs(50.0 - d) / 5.0;
    return min(walk, fly);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> src.x >> src.y;
    cin >> dest.x >> dest.y;
    int N;
    cin >> N;
    P = vector<pt>(N);
    rep(i, 0, N) {
        cin >> P[i].x >> P[i].y;
    }
    vector<vector<ld>> T(N + 2, vector<ld>(N + 2, 1e10));
    rep(i, 0, T.size()) {
        bool f = i < N;
        pt a = get_pt(i);
        rep(j, 0, T.size()) {
            if (i == j) T[i][j] = 0;
            else {
                pt b = get_pt(j);
                T[i][j] = calc(a, b, f);
            }
        }
    }
    rep(k, 0, T.size()) {
        rep(i, 0, T.size()) {
            rep(j, 0, T.size()) {
                ld t = T[i][k] + T[k][j];
                if (t < T[i][j]) T[i][j] = t;
            }
        }
    }
    cout << T[N][N + 1] << endl;
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
