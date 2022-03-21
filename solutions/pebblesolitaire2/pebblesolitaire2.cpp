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

vector<int> T;

int key(string &s) {
    int res = 0;
    for (char c : s) {
        res <<= 1;
        if (c == 'o') res += 1;
    }
    return res;
}

bool possible(string &s, int a, int b, int c, string &next) {
    if (a < 0 || b < 0 || c < 0) return false;
    if (s[a] == '-' && s[b] == 'o' && s[c] == 'o') {
        next = s;
        next[a] = 'o';
        next[b] = '-';
        next[c] = '-';
        return true;
    }
    swap(a, c);
    if (s[a] == '-' && s[b] == 'o' && s[c] == 'o') {
        next = s;
        next[a] = 'o';
        next[b] = '-';
        next[c] = '-';
        return true;
    }
    return false;
}

uint solve(string &s) {
    int k = key(s);
    if (T[k] != -1) return T[k];
    uint count = 0;
    uint best = -1;
    rep(i, 0, s.size()) {
        if (s[i] == 'o') ++count;
        string next;
        if (possible(s, i - 3, i - 2, i - 1, next)) {
            best = min(best, solve(next));
        }
        if (possible(s, i - 2, i - 1, i, next)) {
            best = min(best, solve(next));
        }
    }
    T[k] = min(count, best);
    return T[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cin.ignore();
    T = vector<int>(1 << 23, -1);
    while (N--) {
        string line;
        getline(cin, line);
        cout << solve(line) << endl; 
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
