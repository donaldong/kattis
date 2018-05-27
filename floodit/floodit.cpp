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

int sum(vector<int> &v) {
    int res = 0;
    for (auto e : v) res += e;
    return res;
}

int bfs(vector<string> &G, char col) {
    int n = G.size();
    if (!(G[0][0] == -1 || G[0][0] == col)) return 0;
    int res = 1;
    queue<pair<int, int>> Q;
    Q.push(mp(0, 0));
    G[0][0] = -2;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        rep(i, 0, 4) {
            int r = DR[i] + cur.first;
            int c = DC[i] + cur.second;
            if (0 <= r && r < n && 0 <= c && c < n) {
                if (G[r][c] == -1 || G[r][c] == col) {
                    res++;
                    G[r][c] = -2;
                    Q.push(mp(r, c));
                }
            }
        }
    }
    return res;
}

void step(vector<string> &G, int &count, char &col) {
    count = 0;
    for (char i = '1'; i <= '6'; ++i) {
        auto g = G;
        int res = bfs(g, i);
        if (res > count) {
            count = res;
            col = i;
        }
    }
}

vector<int> solve(vector<string> &G) {
    vector<int> moves(6, 0);
    int n = G.size();
    bool beg = true;
    while (true) {
        int count;
        char col;
        step(G, count, col);
        if (beg) beg = false;
        else moves[col - '1']++;
        if (count == n * n) break;
        bfs(G, col);
        rep(i, 0, n) rep(j, 0, n) {
            if (G[i][j] == -2) G[i][j] = -1;
        }
    }
    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> G(N);
        rep(i, 0, N) cin >> G[i];
        auto res = solve(G);
        cout << sum(res) << endl;
        for (int r : res) cout << r << " ";
        cout << endl;
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
