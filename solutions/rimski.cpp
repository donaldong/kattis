/**
 *  @brief   Kattis - Rimski 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/05/2018
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> a = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> b = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    hmap<string, vector<int>> M;
    hmap<int, string> MM;
    rep(i, 0, a.size()) {
        string s = a[i];
        int v = i + 1;
        MM[v] = s;
        sort(s.begin(), s.end());
        M[s].pb(v);
    }
    rep(i, 0, b.size()) {
        int v = (i + 1) * 10;
        string s = b[i];
        MM[v] = s;
        sort(s.begin(), s.end());
        M[s].pb(v);
        rep(j, 0, a.size()) {
            s = b[i] + a[j];
            v = (i + 1) * 10 + j + 1;
            MM[v] = s;
            sort(s.begin(), s.end());
            M[s].pb(v);
        }
    }
    for (auto &entry : M) {
        sort(entry.second.begin(), entry.second.end());
    }
    string key;
    cin >> key;
    sort(key.begin(), key.end());
    cout << MM[M[key][0]] << endl;
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
