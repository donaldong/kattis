/**
 *  @brief   Kattis - Chess 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/10/2018
 *  
 *  + Implementation
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

struct point {
    char r = -1, c = -1;
    int y = -1, x = -1;
    void calc() {
        if (r != -1 && c != -1) {
            y = r - '1';
            x = c - 'A';
        } else {
            r = y + '1';
            c = x + 'A';
        }
    }
    bool white() { return (y + x) & 1; }
    bool equals(point &p) {
        return y == p.y && x == p.x;
    }
    string to_string() {
        string res;
        res += c;
        return res + " " + r;
    }
};

ull getkey(int y, int x) {
    ull res = y;
    res <<= 32;
    return res + x;
}

vector<int> DY = {-1, -1, 1, 1};
vector<int> DX = {-1, 1, -1, 1};

point intersect(point &a, point &b) {
    hset<ull> S;
    for (int i = 0; i < 4; ++i) {
        int ax = a.x, ay = a.y;
        while (ax >= 0 && ax < 8 && ay >= 0 && ay < 8) {
            S.insert(getkey(ay, ax));
            ax += DX[i]; ay += DY[i];
        }
    }
    for (int i = 0; i < 4; ++i) {
        int bx = b.x, by = b.y;
        while (bx >= 0 && bx < 8 && by >= 0 && by < 8) {
            ull key = getkey(by, bx);
            if (S.find(key) != S.end()) {
                point c;
                c.x = bx;
                c.y = by;
                c.calc();
                return c;
            }
            bx += DX[i]; by += DY[i];
        }
    }
    return point();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        point a, b;
        cin >> a.c >> a.r >> b.c >> b.r;
        a.calc(); b.calc();
        if (a.white() != b.white()) cout << "Impossible" << endl;
        else {
            if (a.equals(b)) cout << 0 << " " << a.to_string() << endl;
            else {
                point c = intersect(a, b);           
                if (b.equals(c)) cout << 1 << " " << a.to_string() << " " << b.to_string() << endl;
                else {
                    cout << 2 << " " << a.to_string() << " " << c.to_string() << " " << b.to_string() << endl;
                }
            }
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
