/**
 *  @brief   Kattis - Kolone 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/04/2018
 *  
 *  + Brute Force
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

struct ant {
    char c;
    bool r;
    int dest;
    ant() {}
    ant(char c, bool r) : c(c), r(r) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, l, t;
    cin >> r >> l;
    vector<ant> A(r + l);
    rep(i, 0, r) {
        cin >> A[i].c;
        A[i].r = true;
        A[i].dest = A.size() - 1 - i;
    }
    rep(i, 0, l) {
        int j = r + i;
        cin >> A[j].c;
        A[j].r = false;
        A[j].dest = i;
    }
    reverse(A.begin(), A.begin() + r);
    cin >> t;
    while (t--) {
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i].r != A[i + 1].r && i != A[i].dest && i + 1 != A[i+1].dest) {
                swap(A[i], A[i + 1]);
                ++i;
            }
        }
    }
    for (auto a : A) cout << a.c;
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
