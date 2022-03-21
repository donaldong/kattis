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

int n, m;

int DR[] = {-1, 0, 0, 1};
int DC[] = {0, -1, 1, 0};
int T = 0;

bool step(vector<vector<int>> &G, int age) {
    bool f = false;
    rep(i, 0, n) rep(j, 0, m) {
        if (G[i][j] == age) {
            rep(k, 0, 4) {
                int r = i + DR[k];
                int c = j + DC[k];
                if (0 <= r && r < n && 0 <= c && c < m) {
                    if (G[r][c] == -1) {
                        G[r][c] = age + 1;
                        T = max(T, G[r][c]);
                        f = true;
                    }
                }
            }
        }
    }
    return f;
}

void solve(vector<vector<int>> &G) {
    step(G, 0);
    int i = 1;
    while (step(G, i++));
}

void print(int e) {
    if (T < 10) {
        if (e == 0) cout << "..";
        else if (e < 10) cout << "." << e;
        else cout << e;
    } else {
        if (e == 0) cout << "...";
        else if (e < 10) cout << ".." << e;
        else if (e < 100) cout << "." << e;
        else cout << e;
    }
}

void print(vector<vector<int>> &G) {
    for (auto &v : G) {
        for (int e : v) print(e);
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(m, -1));
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, m) {
            if (s[j] == '.') G[i][j] = 0;
            else if (i == 0 || i + 1 == n || j == 0 || j + 1 == m) G[i][j] = 1; 
        }
    }
    solve(G);
    print(G);
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
