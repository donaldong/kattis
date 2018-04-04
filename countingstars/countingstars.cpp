/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    02/21/2018
 *  
 *  + BFS
 *  + Graph
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

int DR[] = {-1, 1, 0, 0};
int DC[] = {0, 0, -1, 1};

struct point {
    int r, c;
    ll key;
    point() {}
    point(int r, int c) {
        this->r = r;
        this->c = c;
        key = r;
        key <<= 32;
        key += c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, C;
    int t = 1;
    while (cin >> R >> C) {
        if (R == 0 || C == 0) break;
        vector<string> G(R);
        hmap<ll, point> M;
        for (int i = 0; i < R; ++i){
            cin >> G[i];
            for (int j = 0; j < C; ++j) {
                if (G[i][j] == '-') {
                    auto p = point(i, j);
                    M[p.key] = p;
                }
            }
        }
        int count = 0;
        while (!M.empty()) {
            auto p = M.begin()->second;
            deque<point> Q;
            Q.push_back(p);
            G[p.r][p.c] = '#';
            M.erase(M.begin());
            while (!Q.empty()) {
                p = Q.front();
                Q.pop_front();
                for (int i = 0; i < 4; ++i) {
                    int r = DR[i] + p.r, c = DC[i] + p.c;
                    if (r < 0 || r >= R) continue;
                    if (c < 0 || c >= C) continue;
                    if (G[r][c] == '-') {
                        G[r][c] = '#';
                        auto np = point(r, c);
                        Q.push_back(np);
                        M.erase(M.find(np.key));
                    }
                }
            }
            ++count;
        }
        cout << "Case " << t << ": " << count << endl;
        ++t;
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
