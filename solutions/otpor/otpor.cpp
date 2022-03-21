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

struct expr {
    bool series;
    vector<ld> R;
    ld eval() {
        ld res = 0.0;
        if (series) {
            for (ld r : R) res += r;
            return res;
        }
        for (ld r : R) res += 1.0 / r;
        return 1.0 / res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ld> R(N);
    rep(i, 0, N) cin >> R[i];
    string line;
    cin >> line;
    stack<expr> S;
    ld res;
    rep(i, 0, line.size()) {
        if (line[i] == '(') S.push(expr());
        else if (line[i] >= '0' && line[i] <= '9') {
            int k = line[i] - '1';
            S.top().R.pb(R[k]);
        } else if (line[i] == '-') {
            S.top().series = true;
        } else if (line[i] == '|') {
            S.top().series = false;
        } else if (line[i] == ')') {
           ld r = S.top().eval();
           S.pop();
           if (S.empty()) res = r;
           else S.top().R.pb(r);
        }
    }
    printf("%.6Lf\n", res);
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
