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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int N, K;
        scan(N); scan(K);
        if (!N && !K) break;
        int sum = 0;
        vector< vector< vector<int> > > T(N, vector<vector<int>>(2));
        rep(i, 0, N) {
            vector<int> C(2);
            scan(C[0]); scan(C[1]);
            sum += C[0] + C[1];
            if (i == 0) {
                T[i][0].pb(C[0]);
                T[i][1].pb(C[1]);
            }
            else if (i == 1) {
                T[i][0] = vector<int>(2);
                T[i][1] = vector<int>(2);
                T[i][0][0] = min(C[0], T[0][0][0]);
                T[i][0][1] = T[0][0][0] + C[0];
                T[i][1][0] = min(C[1], T[0][1][0]);
                T[i][1][1] = T[0][1][0] + C[1];
            } else {
                rep(j, 0, 2) {
                    int v = min(C[j], T[i - 1][j][0]);
                    v = min(v, T[i - 2][!j][0]);
                    T[i][j][0] = v;
                    rep(k, 1, i + 1) {
                        v = min(T[i - 1][j][k - 1] + C[j], T[i - 1][j][k]);
                        rep(a, 1, k + 1) {
                            v = min(v, T[i - a][!j][a]
                        }
                    }
                }
            }
        }
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
