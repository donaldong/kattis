/**
 *  @brief   Kattis - Bus Numbers 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/10/2018
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

vector<int> bus() {
    int N = 400000;
    int icube = 1, jcube = 1;
    vector<int> M(N, 0);
    vector<int> S;
    for (int i = 1; (icube = i * i * i) <= N; ++i) {
        for (int j = i; (jcube = j * j * j) + icube <= N; ++j) {
            int k = icube + jcube;
            ++M[k];
            if (M[k] == 2) S.pb(k);
        }
    }
    sort(S.begin(), S.end());
    return S;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto S = bus();
    int m;
    cin >> m;
    auto itr = lower_bound(S.begin(), S.end(), m);
    if (*itr == m) cout << m << endl;
    else if (itr == S.begin()) cout << "none" << endl;
    else cout << *(--itr) << endl;
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
