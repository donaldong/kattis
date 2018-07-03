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

int INF = 1 << 30;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void parse(string &s, int &opt, int &num) {
    string a, b;
    stringstream ss(s);
    ss >> a >> b >> num;
    if (a == "greater") opt = 0;
    else if (a == "less") opt = 1;
    else opt = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int less_than = INF;
        int greater_than = 0;
        int f = 1;
        int N;
        string line;
        getline(cin, line);
        N = stoi(line);
        if (!N) break;
        while (N--) {
            getline(cin, line);
            int opt, num;
            parse(line, opt, num);
            if (opt == 0) {
                greater_than = max(greater_than, num); 
            } else if (opt == 1) {
                less_than = min(less_than, num);
            } else {
                f = lcm(f, num);
            }
        }
        if (less_than == INF) cout << "infinite" << endl;
        else {
            bool flag = false;
            rep(i, greater_than + 1, less_than) {
                if (i % f == 0) {
                    flag = true;
                    cout << i << " ";
                }
            }
            if (!flag) cout << "none" << endl;
            else cout << endl;
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
