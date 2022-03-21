/**
 *  @brief   Kattis - Sort of Sorting 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/07/2018
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
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

struct name {
    char a, b;
    int c;
    string s;
    name() {}
    name(string &s, int i) : s(s), c(i) {
        a = s[0];
        b = s[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (!n) break;
        vector<name> V(n);
        rep(i, 0, n) {
            string s;
            cin >> s;
            V[i] = name(s, i);
        }
        sort(V.begin(), V.end(), [](const name &a, const name &b) {
            if (a.a != b.a) return a.a < b.a;
            if (a.b != b.b) return a.b < b.b;
            return a.c < b.c;
        });
        for (auto &e : V) {
            cout << e.s << endl;
        }
        cout << endl;
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
