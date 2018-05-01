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

void print(vector<int> &V) {
    rep(i, 0, V.size()) {
        cout << V[i] << " ";
    }
    cout << endl;
    cout << endl;
}

vector<int> comb(vector<int> &A, vector<int> &B) {
    vector<int> res(A.size() + B.size());
    bool f = true;
    int a = 0, b = 0;
    rep(i, 0, res.size()) {
        if (f) res[i] = A[a++];
        else res[i] = B[b++];
        f = !f;
    }
    return res;
}

bool done(vector<int> &N) {
    rep(i, 0, N.size()) {
        if (N[i] != i) return false;
    }
    return true;
}

int solve(int n, string &cmd) {
    bool f = cmd != "in";
    vector<int> N(n);
    rep(i, 0, n) N[i] = i;
    int count = 0;
    do {
        vector<int> A, B;
        if (n & 1 && f) {
            int k = n / 2 + 1;
            A = vector<int>(N.begin(), N.begin() + k);
            B = vector<int>(N.begin() + k, N.end()); 
        } else { 
            A = vector<int>(N.begin(), N.begin() + n / 2);
            B = vector<int>(N.begin() + n / 2, N.end());
        }
        if (f) N = comb(A, B);
        else N = comb(B, A);
        ++count;
    } while (!done(N));
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string cmd;
    cin >> n >> cmd;
    cout << solve(n, cmd) << endl;
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
