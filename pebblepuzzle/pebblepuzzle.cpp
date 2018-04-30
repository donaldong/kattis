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

void print(vector<bool> &v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
}

struct row {
    vector<bool> v;
    row() {}
    row(int n) {
        v = vector<bool>(n);
    }
    void flip() {
        rep(i, 0, v.size()) v[i] = !v[i];
    }
    int count() {
        int sum = 0;
        rep(i, 0, v.size()) {
            if (v[i]) ++sum;
        }
        return sum;
    }
};

bool fix(row &a, row &b) {
    int c1 = a.count();
    int c2 = b.count();
    if (c1 == c2) return true;
    if (c1 + c2 != a.v.size()) return false;
    if (c1 > c2) b.flip();
    else a.flip();
    return true;
}

void sort(vector<row> &G, int end) {
    int size = G.back().v.size();
    vector<pair<__int128, int>> res(size);
    rep(i, 0, size) {
        __int128 r = G[0].v[i];
        rep(j, 1, end + 1) {
            r <<= 1;
            r += G[j].v[i];
        }
        res[i] = mp(r, i);
    }
    sort(res.rbegin(), res.rend());
    vector<row> B = G;
    rep(i, 0, G.size()) {
        rep(j, 0, size) {
            B[i].v[j] = G[i].v[res[j].second];
        }
    }
    G = B;
}

bool equal(vector<row> &A, vector<row> &B, size_t end) {
    for (int i = 0; i <= end; ++i) {
        rep(j, 0, A[i].v.size()) {
            if (A[i].v[j] != B[i].v[j]) return false;
        }
    }
    return true;
}

void print(vector<row> &G) {
    for (auto &r : G) {
        for (auto cell : r.v) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool equal(vector<row> &A, vector<row> &B) {
    if (!fix(A[0], B[0])) return false;
    sort(A, 0);
    sort(B, 0);
    rep(i, 1, A.size()) {
        if (!fix(A[i], B[i])) return false;
        sort(A, i);
        sort(B, i);
        if (!equal(A, B, i)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<row> A(n, row(m));
        auto B = A;
        rep(i, 0, n) rep(j, 0, m) {
            string col;
            cin >> col;
            A[i].v[j] = col == "RED";
        }
        rep(i, 0, n) rep(j, 0, m) {
            string col;
            cin >> col;
            B[i].v[j] = col == "RED";
        }
        cout << (equal(A, B) ? "YES" : "NO") << endl;
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
