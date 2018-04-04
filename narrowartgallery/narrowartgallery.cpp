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

struct node {
    int val, i, j;
    bool f = false;
    node() {}
    node(int i, int j, int val) : i(i), j(j), val(val) {}
};

int DR[] = {0, 0, 1};
int DC[] = {1, -1, 0};

int best;
int _END;

void solve(vector<vector<node*>> &G, int i, int j, int k, int count, int res) {
    if (i < 0 || i >= G.size()) return;
    if (j < 0 || j >= 2) return;
    if (G[i][j]->f) return;
    if (_END - i > k - count) return;
    res += G[i][j]->val;
    if (count == k && i == _END) {
        best = max(best, res);
        return;
    }
    G[i][j]->f = true;
    ++count;
    rep(dir, 0, 3) {
        solve(G, i + DR[dir], j + DC[dir], k, count, res);
    }
    G[i][j]->f = false;
}

int solve(vector<vector<node*>> &G, int k) {
    best = 0;
    k = 2 * G.size() - k;
    _END = G.size() - 1;
    solve(G, 0, 0, k, 1, 0);
    solve(G, 0, 1, k, 1, 0);
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while (true) {
        scan(n); scan(k);
        if (!n && !k) break;
        vector<vector<node*>> G(n, vector<node*>(2, 0));
        rep(i, 0, n) {
            rep(j, 0, 2) {
                int v;
                scan(v);
                G[i][j] = new node(i, j, v);
            }
        }
        cout << solve(G, k) << endl;
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
