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
    int a, b;
    node() {}
    node(int a) : a(a), b(a) {}
    node(int a, int b) : a(a), b(b) {}
    bool valid() {
        return b - a >= 1;
    }
};

string get(string &s, node &n) {
    return s.substr(n.a, n.b - n.a + 1);
}

vector<string> solve(string &s) {
    queue<node> Q;
    rep(i, 0, s.size()) Q.push(node(i));
    rep(i, 1, s.size()) {
        if (s[i] == s[i - 1]) {
            Q.push(node(i - 1, i));
        }
    }
    vector<string> res;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (cur.valid()) {
            res.pb(get(s, cur));
        }
        int a = cur.a - 1, b = cur.b + 1;
        if (a >= 0 && b < s.size()) {
            if (s[a] == s[b]) Q.push(node(a, b));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        auto res = solve(line);
        sort(res.begin(), res.end());
        auto end = unique(res.begin(), res.end());
        for (auto itr = res.begin(); itr != end; ++itr) cout << *itr << endl;
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
