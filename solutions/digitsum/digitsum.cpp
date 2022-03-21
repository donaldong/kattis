/**
 *  @brief   Kattis - Digit Sum 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + DP
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

ull calc(string a) {
  uint64_t res = 0;
  uint64_t num = 0;
  uint64_t pow = 1;
  uint64_t ppow = 1;
  for (uint64_t i = 0; i < a.size(); ++i)
  {
    uint64_t d = a[a.size()-i-1] - '0';
    if (0 == i)
      res += d * (d+1) / 2;
    else
    {
      res += d * (d-1) / 2 * pow;
      res += d * i * 45 * ppow;
      res += d * (num+1);
    }
    num += d * pow;
    ppow = pow;
    pow *= 10;
  }
  return res;
}

ull solve(ll a, ll b) {
    if (a <= 0) return calc(to_string(b));
    return calc(to_string(b)) - calc(to_string(a));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    scan(N);
    while (N--) {
        ll a, b;
        scan(a), scan(b);
        --a;
        cout << solve(a, b) << endl;
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
