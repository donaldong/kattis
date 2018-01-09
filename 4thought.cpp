/**
 *  @brief   Kattis - 4 thought 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/04/2018
 *  
 *  + Brute Force
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

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

char priority(char o) {
    if (o == '+' || o == '-') return 1;
    return 2;
}

int calc(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    return a / b;
}

int calc(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (c == '4') s.push(4);
        else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(calc(b, a, c));
        }
    }
    return s.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    hmap<int, string> M;
    string OP = "+-*/";
    rep(i, 0, 4) rep(j, 0, 4) rep(k, 0, 4) {
        string op; op += OP[i]; op += OP[j]; op += OP[k];
        string exp;
        stack<char> s;
        for (char c : op) {
            exp += '4';
            while (!s.empty() && priority(c) <= priority(s.top())) {
                exp+= s.top();
                s.pop();
            }
            s.push(c);
        }
        exp += '4';
        while (!s.empty()) {
            exp += s.top();
            s.pop();
        }
        int res = calc(exp);
        M[res] = op;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (M.find(n) == M.end()) cout << "no solution" << endl;
        else {
            string op = M[n];
            for (char c : op) cout << "4 " << c << " ";
            cout << "4 = " << n << endl;
        }
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
