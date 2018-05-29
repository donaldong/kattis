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

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

struct pt {
    int r, c;
    pt() {}
    pt(int r, int c) : r(r), c(c) {}
    void step(int i) {
        r += DR[i];
        c += DC[i];
    }
};

void print(int n) {
    rep(i, 0, n) cout << '#';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    hmap<string, int> DIR;
    DIR["down"] = 3;
    DIR["up"] = 2;
    DIR["left"] = 0;
    DIR["right"] = 1;
    int b = 0, l = 0, r = 0, t = 0;
    pt cur(0, 0);
    deque<pt> Q;
    string s;
    while (cin >> s) {
        if (DIR.find(s) == DIR.end()) break;
        cur.step(DIR[s]);
        Q.pb(cur);
        b = min(b, cur.r);
        l = min(l, cur.c);
        t = max(t, cur.r);
        r = max(r, cur.c);
    }
    int R = t - b + 1, C = r - l + 1;
    vector<string> G(R, string(C, ' '));
    while (Q.size() > 1) {
        cur = Q.front();
        Q.pop_front();
        G[cur.r - b][cur.c - l] = '*';
    }
    cur = Q.front();
    G[-b][-l] = 'S';
    G[cur.r - b][cur.c - l] = 'E';
    print(C + 2); cout << endl;
    rep(i, 0, R) {
        print(1);
        cout << G[i];
        print(1);
        cout << endl;
    }
    print(C + 2); cout << endl;
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
