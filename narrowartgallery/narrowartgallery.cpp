/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + DP
 *  + Memo
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

vector<vector<int>> G;
vector<vector<vector<int>>> T;

int solve(int n, int k, int opt) {
    if (k < 0) return -1;
    if (T[n][k][opt] != -2) return T[n][k][opt];
    if (n == 0) {
        if (k == 0 && opt == 2) T[n][k][opt] = max(T[n][k][opt], G[n][0] + G[n][1]);
        else if (k == 1 && opt == 0) T[n][k][opt] = max(T[n][k][opt], G[n][1]);
        else if (k == 1 && opt == 1) T[n][k][opt] = max(T[n][k][opt], G[n][0]);
        else T[n][k][opt] = -1;
        return T[n][k][opt];
    }
    int best = -1;
    int res;
    if (opt == 0) {
        res = solve(n - 1, k - 1, 0);
        if (res >= 0) best = max(best, res + G[n][1]);
        res = solve(n - 1, k - 1, 2);
        if (res >= 0) best = max(best, res + G[n][1]);
    } else if (opt == 1) {
        res = solve(n - 1, k - 1, 1);
        if (res >= 0) best = max(best, res + G[n][0]);
        res = solve(n - 1, k - 1, 2);
        if (res >= 0) best = max(best, res + G[n][0]);
    } else if (opt == 2) {
        rep(i, 0, 3) {
            int sum = G[n][0] + G[n][1];
            res = solve(n - 1, k, i);
            if (res >= 0) best = max(best, res + sum);
        }
    }
    T[n][k][opt] = best;
    return best;
}

int solve(int n, int k) {
    --n;
    int res = -2;
    rep(i, 0, 3) {
        res = max(res, solve(n, k, i));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int N, K;
        scan(N); scan(K);
        if (!N && !K) break;
        G = vector<vector<int>>(N, vector<int>(2));
        T = vector<vector<vector<int>>>(N, vector<vector<int>>(K + 1, vector<int>(3, -2)));
        rep(i, 0, N) rep(j, 0, K + 1) rep(k, 0, 3) {
            T[i][j][k] = -2;
        }
        rep(i, 0, N) {
            rep(j, 0, 2) {
                scan(G[i][j]);
            }
        }
        cout << solve(N, K) << endl;
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
