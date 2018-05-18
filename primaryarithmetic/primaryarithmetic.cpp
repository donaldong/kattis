/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Brute Force
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

int solve(string &a, string &b) {
    if (a.size() < b.size()) swap(a, b);
    vector<int> d(a.size(), 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    rep(i, 0, b.size()) {
        d[i] += b[i] - '0';
    }
    rep(i, 0, a.size()) {
        d[i] += a[i] - '0';
    }
    int res = 0;
    for (int i = 0; i < d.size(); ++i) {
        int k = d[i] / 10;
        if (k != 0) ++res;
        d[i] %= 10;
        if (i + 1 < d.size()) d[i + 1] += k;
        else if (k >= 1) d.pb(k);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    while (cin >> a >> b) {
        if (a == "0" && b == "0") break;
        int res = solve(a, b);
        if (res == 0) cout << "No carry operation." << endl;
        else if (res == 1) cout << "1 carry operation." << endl;
        else cout << res << " carry operations." << endl;
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
