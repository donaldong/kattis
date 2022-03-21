/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + DP
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
    int T;
    scan(T);
    while (T--) {
        int N;
        scan(N);
        vector<int> V(N);
        rep(i, 0, N) scan(V[i]);
        vector<vector<uint>> T(N, vector<uint>(1001, -1));
        vector<vector<int>> D(N, vector<int>(1001, 0));
        T[0][V[0]] = V[0];
        D[0][V[0]] = 1;
        rep(i, 1, N) {
            rep(j, 0, 1001) {
                if (T[i - 1][j] == -1) continue;
                uint down = j - V[i];
                if (j >= V[i] && T[i - 1][j] < T[i][down]) {
                    T[i][down] = T[i - 1][j];
                    D[i][down] = -1;
                }
                uint up = j + V[i];
                if (up < 1001 && max(up, T[i - 1][j]) < T[i][up]) {
                    T[i][up] = max(up, T[i - 1][j]);
                    D[i][up] = 1;
                }
            }
        }
        if (T[N - 1][0] == -1) cout << "IMPOSSIBLE" << endl;
        else {
            string res;
            int cur = 0;
            for (int i = N - 1; i >= 0; --i) {
                if (D[i][cur] == -1) res += 'D';
                else res += 'U';
                cur -= D[i][cur] * V[i];
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
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
