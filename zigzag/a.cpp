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

void print(char &c, int &i, int v) {
    if (i & 1) {
        c -= v;
    } else {
        c += v;
    }
    ++i;
    cout << c;
}

void print(vector<int> &v) {
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
        sum += v[i];
    }
    cout << "[" << sum << "]";
    cout << endl;
}

vector<int> balance(int k) {
    int n = k / 25;
    int r = k % 25;
    if (r) ++n;
    int avg = k / n;
    vector<int> res(n, avg);
    if (n == 1) return res;
    int j = n - 1;
    r = k % n;
    if ((r + n) & 1) --j;
    while (r) {
        res[j--]++;
        if (j < 0) j += n;
        r--;
    }
    for (int i = res.size() - 1; i >= 2; i--) {
        int left = 25 - res[i];
        res[i] += left;
        res[i - 2] -= left;
    }
    print(res);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    scan(k);
    auto B = balance(k);
    char prev = 'a';
    int i = 0;
    cout << prev;
    for (int b : B) print(prev, i, b);
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
