/**
 *  @brief   Kattis - Knights in Fen 
 *  @author  Donald Dong (@donaldong)
 *  @date    03/14/2018
 *  
 *  + Graph
 *  + Chess
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

ull getkey(vector<char> &v) {
    ull res = 0;
    for (auto i : v) res = res * 3 + i;
    return res;
}

struct node {
    int step, r, c;
    ull key;
    vector<char> G;
};

int at(int r, int c) {
    return 5 * r + c;
}

void swap(vector<char> &V, int r, int c, int r1, int c1) {
    swap(V[at(r, c)], V[at(r1, c1)]);
}

int DR[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int DC[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    node goal;
    goal.G = {
        1, 1, 1, 1, 1,
        0, 1, 1, 1, 1,
        0, 0, 2, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 0, 0
    };
    goal.step = 0;
    goal.r = goal.c = 2;
    goal.key = getkey(goal.G);
    hmap<ull, int> M;
    queue<node> Q;
    Q.push(goal);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int r = cur.r + DR[i];
            int c = cur.c + DC[i];
            if (r >= 0 && r < 5 && c >= 0 && c < 5) {
                node next;
                next.G = cur.G;
                next.step = cur.step + 1;
                next.r = r;
                next.c = c;
                swap(next.G, r, c, cur.r, cur.c);
                next.key = getkey(next.G);
                if (M.find(next.key) != M.end()) {
                    if (M[next.key] <= next.step) continue;
                }
                M[next.key] = next.step;
                if (next.step < 10) Q.push(next);
            }
        }
    }
    int t;
    string line;
    getline(cin, line);
    t = stoi(line);
    while (t--) {
        vector<char> v(25);
        for (int i = 0; i < 5; ++i) {
            getline(cin, line);
            for (int j = 0; j < 5; ++j) {
                int k = at(i, j);
                if (line[j] == '0') v[k] = 0;
                else if (line[j] == '1') v[k] = 1;
                else v[k] = 2;
            }
        }
        ull key = getkey(v);
        if (key == goal.key) cout << "Solvable in 0 move(s)." << endl;
        else if (M[key] == 0 || M[key] > 10) cout << "Unsolvable in less than 11 move(s)." << endl;
        else cout << "Solvable in " << M[key] << " move(s)." << endl;
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
