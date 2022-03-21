/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Puzzle
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

void print(vector<vector<bool>> &G) {
    rep(i, 0, G.size()) {
        rep(j, 0, G[i].size()) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool even(vector<bool> &v) {
    int count = 0;
    rep(i, 0, v.size()) {
        if (v[i]) ++count;
    }
    int r = v.size() - count;
    if (r == count) return true;
    if (r > count) {
        rep(i, 0, v.size()) {
            v[i] = !v[i];
        }
    }
    return false;
}

void extract(vector<vector<bool>> &a, vector<vector<bool>> &b,
    vector<vector<bool>> &c) {
    rep(i, 0, a.size()) {
        if (even(a[i])) {
            c.pb(a[i]);
        } else {
            b.pb(a[i]);
        }
    }
}

vector<int> sort(vector<vector<bool>> &G) {
    if (G.empty()) return vector<int>();
    int size = G.back().size();
    vector<pair<__int128, int>> res(size);
    rep(i, 0, size) {
        __int128 r = G[0][i];
        rep(j, 1, G.size()) {
            r <<= 1;
            r += G[j][i];
        }
        res[i] = mp(r, i);
    }
    sort(res.rbegin(), res.rend());
    vector<int> v(size);
    rep(i, 0, size) v[i] = res[i].second;
    vector<vector<bool>> B = G;
    rep(i, 0, G.size()) {
        rep(j, 0, G[i].size()) {
            B[i][j] = G[i][v[j]];
        }
    }
    G = B;
    return v;
}

bool equal(vector<vector<bool>> &A, vector<vector<bool>> &B) {
    rep(i, 0, A.size()) {
        rep(j, 0, A[i].size()) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

void fix(vector<vector<bool>> &G, const vector<int> &C) {
    if (G.empty()) return;
    int last_index = G.back().size() - 1;
    rep(i, 0, G.size()) {
        int k;
        if (C.empty()) k = last_index;
        else k = C[last_index];
        if (!G[i][k]) {
            rep(j, 0, G[i].size()) {
                G[i][j] = !G[i][j];
            }
        }
    }
    sort(G);
}

bool possible(vector<vector<bool>> &A, vector<vector<bool>> &B) {
    vector<vector<bool>> a, b, c, d;
    extract(A, a, b);
    extract(B, c, d);
    if (a.size() != c.size()) return false;
    auto C1 = sort(a);
    auto C2 = sort(c);
    if (!equal(a, c)) return false;
    fix(b, C1);
    fix(d, C2);
    return equal(b, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> A(n, vector<bool>(m));
        auto B = A;
        rep(i, 0, n) rep(j, 0, m) {
            string col;
            cin >> col;
            A[i][j] = col == "RED";
        }
        rep(i, 0, n) rep(j, 0, m) {
            string col;
            cin >> col;
            B[i][j] = col == "RED";
        }
        cout << (possible(A, B) ? "YES" : "NO") << endl;
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
