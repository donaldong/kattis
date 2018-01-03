/**
 *  @brief   Kattis - Paradox With Averages 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/02/2017
 *  
 *  + Counting
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

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

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

inline void print(int n) {
    if (n == 0) {
        putchar_unlocked('0');
        putchar_unlocked('\n');
    } else if (n == -1) {
        putchar_unlocked('-');
        putchar_unlocked('1');
        putchar_unlocked('\n');
    } else {
        char buf[11];
        buf[10] = '\n';
        int i = 9;
        while (n) {
            buf[i--] = n % 10 + '0';
            n /= 10;
        }
        while (buf[i] != '\n') putchar_unlocked(buf[++i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    scan(T);
    while (T--) {
        while(getchar() != '\n');
        int a, b;
        scan(a); scan(b);
        vector<int> A(a), B(b);
        ll sa = 0, sb = 0;
        for (int &e : A) { scan(e); sa += e; }
        for (int &e : B) { scan(e); sb += e; }
        ld ra = sa, rb = sb;
        ra /= a; rb /= b;
        int res = 0;
        for (int e : A) {
            ld x = sa - e, y = sb + e;
            x /= a - 1, y /= b + 1;
            if (x > ra && y > rb) ++res;
        }
        print(res);
    }
    return 0;
}
