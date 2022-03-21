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

struct node {
    int i;
    vector<node*> in, out;
    bool safe = true;
    node() {}
    node(int i) : i(i) {}
};

hmap<string, node*> M;

node* get(string &s) {
    if (M.find(s) != M.end()) return M[s];
    int k = M.size();
    auto n = new node(k);
    M[s] = n;
    return n;
}

void dfs() {
    stack<node*> S;
    for (auto &entry : M) {
        if (entry.second->out.empty()) {
            entry.second->safe = false;
            S.push(entry.second);
        }
    }
    while (!S.empty()) {
        auto cur = S.top();
        S.pop();
        for (auto n : cur->in) {
            int count = 0;
            for (auto nn : n->out) {
                if (nn->safe) ++count;
            }
            if (!count) {
                n->safe = false;
                S.push(n);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        string a, b;
        cin >> a >> b;
        auto i = get(a);
        auto j = get(b);
        i->out.pb(j);
        j->in.pb(i);
    }
    dfs();
    string city;
    while (cin >> city) {
        auto k = get(city);
        cout << city << " ";
        cout << (k->safe ? "safe" : "trapped") << endl;
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
