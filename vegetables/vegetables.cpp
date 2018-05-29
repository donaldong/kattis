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

struct node {
    int len;
    int c = 0;
    node() {}
    node(int len) : len(len) {}
};

struct cmp {
    bool operator() (node *a, node *b) const {
        ld l = a->len, r = b->len;
        l /= a->c + 1;
        r /= b->c + 1;
        if (abs(l - r) <= 1e-9) {
            if (a->len == b->len) return ull(a) < ull(b);
            return a->len > b->len;
        }
        return l < r;
    }
};

ld get_ratio(set<node*, cmp> &S) {
    auto a = *S.begin();
    auto b = *prev(S.end());
    ld lo = a->len, hi = b->len;
    lo /= a->c + 1; hi /= b->c + 1;
    return lo / hi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ld T;
    int N;
    cin >> T >> N;
    set<node*, cmp> S;
    rep(i, 0, N) {
        int l;
        cin >> l;
        S.insert(new node(l));
    }
    int count = 0;
    while (get_ratio(S) < T) {
        auto n = *prev(S.end());
        S.erase(n);
        ++n->c;
        ++count;
        S.insert(n);
    }
    cout << count << endl;
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
