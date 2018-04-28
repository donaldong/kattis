/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Brute Force
 *  + Permutation
 *  + Prime number
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

vector<bool> P;
hset<int> used;

vector<string> solve(string &s, int &count) {
    vector<string> res;
    if (s.size() == 1) {
        int n = s[0] - '0';
        if (P[n] && used.find(n) == used.end()) {
            ++count;
            used.insert(n);
        }
        res.pb(s);
        return res;
    }
    rep(i, 0, s.size()) {
        char cur = s[i];
        string next = s;
        next.erase(next.begin() + i);
        auto r = solve(next, count);
        for (string e : r) {
            e = cur + e;
            int k = stoi(e);
            if (P[k] && used.find(k) == used.end()) {
                ++count;
                used.insert(k);
            }
            res.pb(e);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    P = vector<bool>(1e8, true);
    P[0] = P[1] = false;
    for (int p=2; p * p < P.size(); ++p) {
        if (P[p]) {
            for (int i = p * p; i < P.size(); i += p) P[i] = false;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        used.clear();
        string s;
        cin >> s;
        int count = 0;
        solve(s, count);
        cout << count << endl;
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
