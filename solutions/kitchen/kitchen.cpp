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

vector<int> C;

struct state {
    vector<int> V;
    int total;
    state() {
        V = vector<int>(C.size(), 0);     
        total = 0;
    }
    state(state *s) {
        V = s->V;
        total = s->total;
    }
    bool pour(int i, int j) {
        int left = C[j] - V[j];
        if (!left) return false;
        left = min(left, V[i]);
        V[j] += left;
        V[i] -= left;
        total += left;
        return true;
    }
    ll key() {
        ll res = V.back();
        for (int i = V.size() - 2; i >= 0; --i) {
            res <<= 7;
            res += V[i];
        }
        return res;
    }
};

int solve(int goal) {
    hmap<ll, state> M;
    queue<state> Q;
    state start;
    start.V[0] = C[0];
    ll key = start.key();
    M[start.key()] = start;
    Q.push(start);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        rep(i, 0, C.size()) {
            rep(j, i + 1, C.size()) {
                state ns(&cur);
                if (ns.pour(i, j)) {
                    ll nk = ns.key();
                    if (M.find(nk) != M.end()) {
                        if (M[nk].total > ns.total) {
                            M[nk] = ns;
                            Q.push(ns);
                        }
                    } else {
                        M[nk] = ns;
                        Q.push(ns);
                    }
                }
                state ns2(&cur);
                if (ns2.pour(j, i)) {
                    ll nk = ns2.key();
                    if (M.find(nk) != M.end()) {
                        if (M[nk].total > ns2.total) {
                            M[nk] = ns2;
                            Q.push(ns2);
                        }
                    } else {
                        M[nk] = ns2;
                        Q.push(ns2);
                    }
                }
            }
        }
    }
    int res = 1e9;
    for (auto &entry : M) {
        if (entry.second.V[0] == goal) {
            res = min(res, entry.second.total);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    scan(N);
    C = vector<int>(N);
    rep(i, 0, N) {
        scan(C[i]);
    }
    int V;
    scan(V);
    auto res = solve(V);
    if (res == 1e9) cout << "impossible" << endl;
    else cout << res << endl;
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
