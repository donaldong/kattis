/**
 *  @brief   Kattis - Flip Five 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/08/2018
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

int N = 1 << 9;
int R = 3, C = 3;
vector<int> DR = {0, 0, 1, -1};
vector<int> DC = {1, -1, 0, 0};

string to_grid(int n) {
    string res;
    while (n) {
       if (n & 1) res += '*';
       else res += '.';
       n /= 2;
    }
    while (res.size() != 9) {
        res += '.';
    }
    reverse(res.begin(), res.end());
    return res;
}

int to_index(string g) {
    int res = 0;
    for (char c : g) {
        res <<= 1;
        if (c == '*') {
            res += 1;
        }
    }
    return res;
}

char flip(char c) {
    if (c == '.') return '*';
    return '.';
}

int at(int r, int c) {
    return r * C + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<uint> V(N, -1);
    vector<bool> F(N, false);
    V[0] = 0;
    F[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        string g = to_grid(i);
        rep(r, 0, R) rep(c, 0, C) {
            string ng = g;
            ng[at(r, c)] = flip(ng[at(r, c)]);
            rep(j, 0, 4) {
                int y = r + DR[j], x = c + DC[j];
                if (y < 0 || y >= R || x < 0 || x >= C) continue;
                ng[at(y, x)] = flip(ng[at(y, x)]);
            }
            int k = to_index(ng);
            V[k] = min(V[k], V[i] + 1);
            if (!F[k]) q.push(k);
            F[k] = true;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        string g;
        rep(i, 0, 3) {
            string s;
            cin >> s;
            g += s;
        }
        cout << V[to_index(g)] << endl;
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
