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

int num(char c) {
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return c - '0';
}

int col(char c, vector<int> &C) {
    if (c == 's') return C[0];
    if (c == 'h') return C[1];
    if (c == 'd') return C[2];
    return C[3];
}

bool rev(char c, int mask) {
    if (c == 's') return mask & 1;
    if (c == 'h') return mask & (1 << 1);
    if (c == 'd') return mask & (1 << 2);
    return mask & (1 << 3);
}

int encode(string &s, int mask, vector<int> &C) {
    int n = num(s[0]);
    if (rev(s[1], mask)) n = 100 - n;
    return n + col(s[1], C);
}

int lis(vector<int> &N) {
    vector<int> L(N.size(), 1);
    int res = 1;
    rep(i, 0, N.size()) {
        rep(j, 0, i) {
            if (N[j] < N[i]) L[i] = max(L[i], L[j] + 1);
        }
        res = max(res, L[i]);
    }
    return res;
}

void print(vector<int> &V) {
    for (auto v : V) cout << v << " ";
    cout << endl;
}

vector<int> apply(vector<string> &N, int mask, vector<int> &C) {
    vector<int> res(N.size());
    rep(i, 0, N.size()) {
        res[i] = encode(N[i], mask, C);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> C(4);
    vector<string> N(n);
    rep(i, 0, 4) C[i] = (i + 1) * 100;
    rep(i, 0, n) cin >> N[i]; 
    int res = n;
    do {
        rep(i, 0, 16) {
            auto v = apply(N, i, C);
            res = min(res, n - lis(v));
        }
    } while (next_permutation(C.begin(), C.end()));
    cout << res << endl;
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
