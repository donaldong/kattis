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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct rat {
    ll p, q = 1;

    rat() {}

    rat(ll x, ll y) {
        p = x; q = y;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        int c = gcd(abs(p), q);
        p /= c;
        q /= c;
    }

    rat operator+(rat const &r) {
        return rat(p * r.q + r.p * q, q * r.q);
    }

    rat operator-(rat const &r) {
        return rat(p * r.q - r.p * q, q * r.q);
    }

    rat operator*(rat const &r) {
        return rat(p * r.p, q * r.q);
    }

    rat operator/(rat const &r) {
        return rat(p * r.q, q * r.p);
    }
};

bool empty_row(vector<vector<rat>> &G, int r) {
    return !G[r][0].p && !G[r][1].p && !G[r][2].p;
}

bool possible(vector<vector<rat>> &G) {
    rep(i, 0, 3) if (G[i][3].p < 0) return false;
    rep(i, 0, 3) {
        int count = 0;
        rep(j, 0, 3) {
            if (G[j][i].p == 1) ++count;
        }
        if (count > 1) return false;
        rat diff;
        diff.p = 1;
        diff = diff - G[i][3];
        if (diff.p < 0) return false;
    }
    rep(i, 0, 3) {
        if (empty_row(G, i)) {
            if (G[i][3].p != 0) return false;
        }
    }
    return true; 
}

void print(vector<rat> &row) {
    for (auto &r : row) {
        cout << " (" << r.p << "/" << r.q << ") ";
    }
}

void print(vector<vector<rat>> &G) {
    for (auto &row : G) {
        print(row);
        cout << endl;
    }
    cout << endl;
}

void eliminate(vector<vector<rat>> &G) {
    rep(k, 0, 3) {
        int max_idx = k;
        rat max_val = G[k][k];
        rep(i, k + 1, 3) {
            rat cur = G[i][k];
            if (cur.p < 0) cur.p *= -1;
            rat diff = cur - max_val;
            if (diff.p > 0) {
                max_val = cur;
                max_idx = i;
            }
        }
        if (!max_val.p) continue;
        if (max_idx != k) swap(G[k], G[max_idx]);
        rep(i, k + 1, 3) {
            rat q = G[i][k] / G[k][k];
            rep(j, k + 1, 4) {
                G[i][j] = G[i][j] - G[k][j] * q;
            }
            G[i][k].p = 0;
            G[i][k].q = 1;
        }
    }
    print(G);
    if (G[2][2].p) {
        G[2][3] = G[2][3] / G[2][2];
        G[2][2].p = 1; G[2][2].q = 1;
    }
   
    if (G[1][2].p) {
        rep(i, 1, 4) {
            if (i == 2) continue;
            G[1][i] = G[1][i] / G[1][2];
        }
        G[1][2].p = 0;
        G[1][3] = G[1][3] - G[2][3];
    }
    if (G[1][1].p) {
        rep(i, 1, 4) {
            if (i == 1) continue;
            G[1][i] = G[1][i] / G[1][1];
        }
        G[1][1].p = G[1][1].q = 1;
    }
    
    if (G[0][2].p) {
        rep(i, 0, 4) {
            if (i == 2) continue;
            G[0][i] = G[0][i] / G[0][2];
        }
        G[0][2].p = 0;
        G[0][3] = G[0][3] - G[2][3];
    }
    if (G[0][1].p) {
        rep(i, 0, 4) {
            if (i == 1) continue;
            G[0][i] = G[0][i] / G[0][1];
        }
        G[0][1].p = 0;
        G[0][3] = G[0][3] - G[1][3];
        G[0][2] = G[0][2] - G[1][2];
    }
    if (G[0][0].p) {
        rep(i, 1, 4) {
            G[0][i] = G[0][i] / G[0][0];
        }
        G[0][0].p = G[0][0].q = 1;
    }
    print(G);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        vector<vector<rat>> G(3, vector<rat>(4));
        rep(i, 0, 4) {
            rep(j, 0, 3) {
                cin >> G[j][i].p;
            }
        }
        if (!G[0][0].p && !G[1][0].p && !G[2][0].p) break;
        eliminate(G);
        cout << (possible(G) ? "YES" : "NO") << endl;
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
