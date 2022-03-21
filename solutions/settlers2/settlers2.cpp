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

int MAX = 10000;
vector<int> F, T;

int fill(int a, int b, int c = 0) {
   vector<pair<int, int>> v;
   for (int i = 1; i <= 5; ++i) {
        if (a == i || b == i || c == i) 
            continue;
        v.pb(mp(F[i], i));
   }
   sort(v.begin(), v.end());
   int res = v[0].second;
   ++F[res];
   return res;
}

void solve(int r, int beg, int i, int k) {
    int last_two = (i - beg) % r;
    int n = (r - 1) * 6;
    int j = i - n - k;
    if (last_two == r - 1 || j < 2) {
        // Only connect to 1
        T[i] = fill(T[i - 1], T[j]);
    } else {
        T[i] = fill(T[i - 1], T[j], T[j - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    F = {0, 1, 0, 0, 0, 0};
    T = vector<int>(MAX, -1);
    int C;
    scan(C);
    T[0] = 1;
    int beg = 1;
    int r = 1;
    for (int i = 1; i < MAX; ++i) {
        int cur = 6 * r;
        int dist = i - beg + 1;
        int k = dist * 6 / cur;
        if (dist == 1) {
            // First one in the ring
            int j = i - 6 * (r - 1);
            if (r == 1) j = 0;
            T[i] = fill(T[i - 1], T[j]);
            continue;
        }
        if (dist == cur) {
            // Last one in the ring
            int n = (r - 1) * 6;
            int j = i - n - k;
            T[i] = fill(T[i - 1], T[beg], T[j]);
            ++r;
            beg = i + 1;
            continue;
        }
        solve(r, beg, i, k);
    }
    while (C--) {
        int N;
        scan(N);
        cout << T[N - 1] << endl;
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
