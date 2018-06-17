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

bool too_close(ll a, ll b) {
    return abs(a - b) < 5;
}

void solve(vector<int> &A, vector<int> &B, int a, int b) {
    rep(i, 1, A.size()) {
        A[i] += A[i - 1];
        B[i] += B[i - 1];
    }
    ll x = 0, y = 0;
    rep(i, 0, A.size()) {
        x += A[i];
        y += B[i];
        if (too_close(x + a, y + b)) {
            cout << "bumper tap at time " << i + 1 << endl;
            return;
        }
    }
    cout << "safe and sound" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    scan(a); scan(b);
    vector<int> A(4e6 + 4, 0);
    auto B = A;
    int n;
    scan(n);
    while (n >= 2) {
        int x, y;
        scan(x); scan(y);
        A[x]++; A[y]--;
        n -= 2;
    }
    if (n) {
        int x;
        scan(x);
        A[x]++;
        A.back()--;
    }
    scan(n);
    while (n >= 2) {
        int x, y;
        scan(x); scan(y);
        B[x]++; B[y]--;
        n -= 2;
    }
    if (n) {
        int x;
        scan(x);
        B[x]++;
        B.back()--;
    }
    solve(A, B, a, b);
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
