/**
 *  @brief   Kattis - Smart Phone 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/03/2018
 *  
 *  + Greedy
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
inline void print(uint);
inline void print(ull);
inline void print(string&);

int dist(string &a, string &b) {
    auto i = b.find(a);
    if (i != 0) {
        int res = 0;
        int size = min(a.size(), b.size());
        rep(i, 0, size) {
            if (a[i] != b[i]) {
                return a.size() + b.size() - 2 * res;
            }   
            ++res;
        }
    }
    int size = a.size();
    size -= b.size();
    return abs(size);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string target, current, s1, s2, s3;
        cin >> target >> current >> s1 >> s2 >> s3;
        int res = INT_MAX;
        res = min(res, dist(current, target));
        res = min(res, dist(s1, target) + 1);
        res = min(res, dist(s2, target) + 1);
        res = min(res, dist(s3, target) + 1);
        cout << res << endl;
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
