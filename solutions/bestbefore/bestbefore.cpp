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

bool leap(int y) {
    if (y % 4 == 0 && y % 100 == 0 && y % 400 != 0) return false;
    return y % 4 == 0;
}

int num_of_days(int y, int m) {
    if (m == 2) return leap(y) ? 29 : 28;
    vector<int> D = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    --m;
    return D[m];
}

struct date {
    string Y, M, D;
    int y, m, d;
    date(string &Y, string &M, string &D) : Y(Y), M(M), D(D) {}
    bool valid() {
        y = stoi(Y);
        if (y > 2999) return false;
        if (y >= 1000 && y < 2000) return false;
        if (y < 2000) y += 2000;
        m = stoi(M);
        if (m > 12) return false;
        if (m == 0) return false;
        d = stoi(D);
        if (d > 31) return false;
        if (d == 0) return false;
        return d <= num_of_days(y, m);
    }
    void print() {
        printf("%d-%02d-%02d\n", y, m, d);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    getline(cin, line);
    vector<string> V(3);
    int k = 0;
    rep(i, 0, line.size()) {
        if (line[i] != '/') V[k] += line[i];
        else ++k;
    }
    vector<date> D;
    sort(V.begin(), V.end());
    do {
        date d(V[0], V[1], V[2]);
        if (d.valid()) D.pb(d);
    } while (next_permutation(V.begin(), V.end()));
    if (D.empty()) cout << line << " is illegal" << endl;
    else {
        sort(D.begin(), D.end(), [](date &a, date &b) {
            if (a.y != b.y) return a.y < b.y;
            if (a.m != b.m) return a.m < b.m;
            return a.d < b.d;
        });
        D[0].print();
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
