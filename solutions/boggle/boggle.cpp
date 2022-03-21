/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Trie
 *  + Grid
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
    bool end;
    string s;
    vector<node*> neigh;
    node() {
       end = false;
       neigh = vector<node*>(26, 0);
    }
};

void insert(node *n, string &s) {
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'A';
        if (!n->neigh[index]) n->neigh[index] = new node();
        n = n->neigh[index];
    }
    n->end = true;
    n->s = s;
}

struct point {
    int r, c;
    node *n = 0;
    point() {}
    point(int r, int c) : r(r), c(c) {}
};

int DR[] = {0, 0, 1, -1, -1, 1, 1, -1};
int DC[] = {1, -1, -1, 1, -1, 1, 0, 0};

bool valid(point &p, vector<string> &G) {
    return p.r >= 0 && p.r < G.size() && p.c >= 0 && p.c < G.back().size();
}

void dfs(vector<string> &G, point &cur, vector<vector<bool>> &F, vector<string> &res) {
    for (int i = 0; i < 8; ++i) {
        point p(cur.r + DR[i], cur.c + DC[i]);
        if (valid(p, G)) {
           int k = G[p.r][p.c] - 'A';
           if (cur.n->neigh[k] && !F[p.r][p.c]) {
               p.n = cur.n->neigh[k];
               F[p.r][p.c] = true;
               dfs(G, p, F, res);
               F[p.r][p.c] = false;
               if (p.n->end) res.pb(p.n->s);
           }
        }
    }
}

vector<string> solve(node *root, vector<string> &G, point start) {
    vector<string> res;
    int k = G[start.r][start.c] - 'A';
    start.n = root->neigh[k];
    if (!start.n) return res;
    vector<vector<bool>> F(G.size(), vector<bool>(G.back().size(), false));
    F[start.r][start.c] = true;
    dfs(G, start, F, res);
    return res;
}

vector<string> solve(node *n, vector<string> &G) {
    vector<string> res;
    rep(i, 0, G.size()) {
        rep(j, 0, G[i].size()) {
            auto r = solve(n, G, point(i, j));
            for (auto &s : r) res.pb(s);
        }
    }
    return res;
}

int get_score(string &s) {
    if (s.size() < 3) return 0;
    if (s.size() <= 4) return 1;
    if (s.size() == 5) return 2;
    if (s.size() == 6) return 3;
    if (s.size() == 7) return 5;
    if (s.size() == 8) return 11;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    auto root = new node();
    while (n--) {
        string s;
        cin >> s;
        insert(root, s);
    }
    cin >> t;
    while (t--) {
        vector<string> G(4);
        for (string &row : G) cin >> row;
        auto s = solve(root, G);
        sort(s.begin(), s.end());
        auto end = unique(s.begin(), s.end());
        int max_len = 0, score = 0, count = 0;
        string res;
        for (auto itr = s.begin(); itr != end; ++itr) {
            score += get_score(*itr);
            if (itr->size() > max_len) {
                max_len = itr->size();
                res = *itr;
            }
            ++count;
        }
        cout << score << " " << res << " " << count << endl;
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
