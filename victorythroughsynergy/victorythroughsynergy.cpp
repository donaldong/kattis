/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Brute Force
 *  + Graph
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

struct player {
    string name, nation, league, team;
};

int calc(player &a, player &b) {
    if (a.team == b.team && a.nation == b.nation) return 3;
    if (a.nation == b.nation && a.league == b.league) return 2;
    if (a.team == b.team) return 2;
    if (a.nation == b.nation) return 1;
    if (a.league == b.league) return 1;
    return 0;
}

bool possible(vector<vector<bool>> &G, vector<vector<int>> &S) {
    vector<int> P = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        bool f = true;
        for (int r = 0; r < 10; ++r) {
            int degree = 0;
            int score = 0;
            for (int c = 0; c < 10; ++c) {
                if (G[r][c]) {
                    ++degree;
                    score += S[P[r]][P[c]];
                }
            }
            if (score < degree) {
                f = false;
                break;
            }
        }
        if (f) return true;
    } while (next_permutation(P.begin(), P.end()));
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    vector<vector<bool>> G(10, vector<bool>(10, false));
    while (c--) {
        int a, b;
        cin >> a >> b;
        G[a][b] = true;
        G[b][a] = true;
    }
    vector<vector<int>> S(10, vector<int>(10, 0));
    vector<player> P(10);
    for (auto &p : P) {
        cin >> p.name >> p.nation >> p.league >> p.team;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j) continue;
            int score = calc(P[i], P[j]);
            S[i][j] = score;
            S[j][i] = score;
        }
    }
    if (possible(G, S)) cout << "yes" << endl;
    else cout << "no" << endl;
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
