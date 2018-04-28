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
    void fix(int size) {
        if (!size) return;
        int sum = 0;
        rep(i, 0, size) {
            if (v[i]) ++sum;
        }
        int sum2 = size - sum;
        if (sum2 > sum) flip(); 
        else if (sum2 == sum) fix(size / 2);
    }

    void init() {
        fix(v.size());
    }

    void flip() {
        rep(i, 0, v.size()) v[i] = !v[i];
    }
};

void print(vector<row> &G) {
    for (auto &r : G) {
        for (auto cell : r.v) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(const vector<__int128> &v) {
    rep(i, 0, v.size()) {
        ll k = v[i];
        cout << k << " ";
    }
    cout << endl;
}

vector<__int128> norm(vector<row> &G) {
    for (auto &r : G) r.init();
    print(G);
    int size = G.back().v.size();
    vector<__int128> res(size);
    rep(i, 0, size) {
        __int128 r = G[0].v[i];
        rep(j, 1, G.size()) {
            r <<= 1;
            r += G[j].v[i];
        }
        res[i] = r;
    }
    sort(res.rbegin(), res.rend());
    return res;
}

bool equal(const vector<__int128> &a, const vector<__int128> &b) {
    rep(i, 0, a.size()) {
        if (a[i] != b[i]) return false;
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
        auto a = norm(A);
        auto b = norm(B);
        cout << (equal(a, b) ? "YES" : "NO") << endl;
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
