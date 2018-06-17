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
vector<pair<ll, int>> F;

void factors(ll n) {
    hmap<ll, int> R;
    while (!(n & 1)) {
        R[2]++;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            R[i]++;
            n /= i;
        }
    }
    if (n > 1) R[n]++;
    int i = 0;
    F = vector<pair<ll, int>>(R.size());
    for (auto &entry : R) {
        F[i++] = entry;
    }
}

ll eval() {
    ll res = 1;
    rep(i, 0, C.size()) {
        res *= pow(F[i].first, C[i]);
    }
    return res;
}

bool step() {
    C[0]++;
    rep(i, 0, C.size() - 1) {
        if (C[i] > F[i].second) {
            C[i] = 0;
            ++C[i + 1];
        } else break;
    }
    return C.back() <= F.back().second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    scan(n);
    factors(n);
    C = vector<int>(F.size(), 0); 
    vector<ll> res;
    do {
        res.pb(eval()); 
    } while (step());
    sort(res.begin(), res.end());
    for (ll r : res) cout << r - 1 << " ";
    cout << endl;
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
