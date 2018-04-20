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
    bool f = false;
    string name;
    vector<node*> neigh;
    node *prev = 0;
};

void bfs(node *a, node *b) {
    queue<node*> Q;
    Q.push(a);
    a->f = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto n : cur->neigh) {
            if (!n->f) {
                n->f = true;
                n->prev = cur; 
                Q.push(n);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    hmap<string, node> M;
    while (n--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string name, token; 
        ss >> name;
        while (ss >> token) {
            M[name].neigh.pb(&M[token]);
            M[token].neigh.pb(&M[name]);
        }
    }
    for (auto &entry : M) {
        entry.second.name = entry.first;
    }
    string src, dest;
    cin >> src >> dest;
    auto cur = &M[dest];
    bfs(&M[src], cur);
    vector<string> res;
    cur = cur->prev;
    while (cur) {
        res.pb(cur->name);
        cur = cur->prev;
    }
    if (res.empty()) cout << "no route found" << endl;
    else {
        for (auto i = res.rbegin(); i != res.rend(); ++i) {
            cout << *i << " ";
        }
        cout << dest << endl;
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

