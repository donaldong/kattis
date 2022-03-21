/**
 *  @brief   Kattis - Restaurant Orders 
 *  @author  Donald Dong (@donaldong)
 *  @date    03/07/2018
 *  
 *  + Memoization
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

struct order {
    bool ambiguous;
    hmap<int, int> prices;
};

hmap<int, order> M;

bool equal(hmap<int, int> &a, hmap<int, int> &b) {
    if (a.size() != b.size()) return false;
    for (auto &entry : a) {
        if (b.find(entry.first) == b.end()) return false;
        if (b[entry.first] != entry.second) return false;
    }
    return true;
}

int solve(int target, vector<int> &P) {
    if (target == 0) return 0;
    if (target < 0) return 2;
    if (M.find(target) != M.end()) {
        auto &cur = M[target];
        if (cur.ambiguous) return 1;
        if (cur.prices.empty()) return 2;
        return 0;
    }
    bool seen = false;
    for (int i = 0; i < P.size(); ++i) {
        int j = target - P[i]; 
        int k = solve(j, P);
        if (k == 1) {
            M[target].ambiguous = true;
            return 1;
        }
        if (k == 0 && j >= 0) {
            hmap<int, int> prices;
            prices[i + 1]++;
            for (auto &entry : M[j].prices) {
                prices[entry.first] += entry.second;
            }
            if (!seen) M[target].prices = prices;
            else if (!equal(prices, M[target].prices)) {
                M[target].ambiguous = true;
                return 1;
            }
            seen = true;
        }
    }
    if (seen) {
        M[target].ambiguous = false;
        return 0;
    }
    M[target].prices.clear();
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scan(n);
    vector<int> P(n);
    hmap<int, int> X;
    for (int &p : P) scan(p);
    int m;
    scan(m);
    while (m--) {
        scan(n);
        int k = solve(n, P);
        if (k == 0) {
            vector<pair<int, int>> V(M[n].prices.size());
            int i = 0;
            for (auto entry : M[n].prices) {
                V[i].first = entry.first;
                V[i].second = entry.second;
                ++i;
            }
            sort(V.begin(), V.end());
            for (i = 0; i < V.size(); ++i) {
                for (int j = 0; j < V[i].second; ++j) {
                    cout << V[i].first << " "; 
                }
            }
            cout << endl;
        } else if (k == 1) cout << "Ambiguous" << endl;
        else cout << "Impossible" << endl;
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
