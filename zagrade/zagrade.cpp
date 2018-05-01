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

struct bracket {
    int a, b;
    bool f;
    bracket() {}
    bracket(int a, int b) : a(a), b(b) {}
};

struct expr {
    vector<bracket> B;
    string s;
    expr() {}
    expr(string &k) {
        stack<int> S;
        s = k;
        rep(i, 0, s.size()) {
            if (s[i] == '(') S.push(i);
            else if (s[i] == ')') {
                B.pb(bracket(S.top(), i));
                S.pop();
            }
        }
    }
    string render(int mask) {
        vector<bool> M(s.size(), true);
        rep(i, 0, B.size()) {
            if (mask & 1) {
                M[B[i].a] = false;
                M[B[i].b] = false;
            }
            mask >>= 1;
        }
        string res;
        rep(i, 0, s.size()) {
            if (M[i]) res += s[i];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    getline(cin, line);
    expr E(line);
    vector<string> V((1 << E.B.size()) - 1);
    rep(i, 1, V.size() + 1) {
        V[i - 1] = E.render(i);
    }
    sort(V.begin(), V.end());
    auto end = unique(V.begin(), V.end());
    for (auto itr = V.begin(); itr != end; ++itr) {
        cout << *itr << endl;
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
