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

vector<bool> B;
bool f = true;

void fill(int n, int k) {
    k *= 3;
    for (int i = 2; i >= 0; --i) {
        B[k + i] = n & 1;
        n /= 2;
    }
}

void print_hex(int n) {
    f = false;
    if (n < 10) cout << n;
    else cout << char('A' + n - 10);
}

void print() {
    for (bool b : B) cout << b;
    cout << endl;
}

void solve(size_t &j) {
    int k = 0;
    rep(i, 0, 4) {
        if (B[j++]) ++k;
        if (i != 3) k <<= 1;
    }
    if (f && !k) return;
    print_hex(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    getline(cin, line);
    B = vector<bool>(line.size() * 3);
    rep(i, 0, line.size()) {
        fill(line[i] - '0', i);
    }
    size_t r = B.size() % 4;
    if (r) {
        int k = 0;
        rep(i, 0, r) {
            if (B[i]) ++k;
            if (i != r - 1) k <<= 1;
        }
        if (k) print_hex(k);
    }
    while (r < B.size()) solve(r);
    if (f) cout << 0;
    cout << endl;
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
