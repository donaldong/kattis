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

void floyd(vector<vector<int>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]
                    && dist[i][k] < 1e9 && dist[k][j] < 1e9) 
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; dist[i][j] != -1e9 && k < V; k++) {
                if (dist[k][k] < 0 && dist[i][k] != 1e9 && dist[k][j] != 1e9) {
						dist[i][j] = -1e9;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    while (true) {
        scan(n); scan(m); scan(q);
        if (!n && !m && !q) break;
        vector<vector<int>> G(n, vector<int>(n, 1e9));
        rep(i, 0, n) G[i][i] = 0;
        while (m--) {
            int u, v, w;
            scan(u); scan(v); scan(w);
            G[u][v] = min(G[u][v], w);
        }
        floyd(G);
        while (q--) {
            int u, v;
            scan(u); scan(v);
            if (G[u][v] == 1e9) cout << "Impossible" << endl;
            else if (G[u][v] == -1e9) cout << "-Infinity" << endl;
            else cout << G[u][v] << endl;
        }
        cout << endl;
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
