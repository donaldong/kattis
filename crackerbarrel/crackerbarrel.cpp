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

int encode(string a) {
    int res = a[0];
    res <<= 8;
    return res + a[1];
}

void decode(int n, char &a, char &b) {
    b = n;
    n >>= 8;
    a = n;
}

struct state {
    vector<vector<int>> G;
    state() {}
    state(vector<vector<int>> &G) : G(G) {}
    string get_key(int &count, int &col) {
        count = 0;
        col = 0;
        string res;
        rep(i, 0, 5) {
            rep(j, 0, G[i].size()) {
                char a, b;
                decode(G[i][j], a, b);
                res += a;
                res += b;
                if (G[i][j] != 0) {
                    col = G[i][j];
                    ++count;
                }
            }
        }
        return res;
    }
};

int DR[] = {0, 0, -1, -1, 1, 1};
int DC[] = {-1, 1, 0, -1, 0, 1};

void print(vector<vector<int>> &G) {
    rep(i, 0, G.size()) {
        rep(j, 0, G[i].size()) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool possible(vector<state> &S, int start) {
    int count, col;
    hset<string> M;
    M.insert(S[0].get_key(count, col));
    if (count == 1 && col == start) return true;
    while (!S.empty()) {
        auto cur = S.back();
        S.pop_back();
        rep(k, 0, 5) rep(j, 0, cur.G[k].size()) {
            if (cur.G[k][j] != 0) continue;
            rep(i, 0, 6) {
                int r = k + DR[i];
                int c = j + DC[i];
                if (r >= 0 && r < 5 && c >= 0 && c <= r) {
                    if (cur.G[r][c] == 0) continue;
                    int nr = r + DR[i];
                    int nc = c + DC[i];
                    if (nr >= 0 && nr < 5 && nc >= 0 && nc <= nr) {
                        if (cur.G[nr][nc] == 0) continue;
                        state new_state(cur.G);
                        new_state.G[k][j] = new_state.G[nr][nc];
                        new_state.G[r][c] = 0;
                        new_state.G[nr][nc] = 0;
                        auto key = new_state.get_key(count, col);
                        if (count == 1 && col == start) return true;
                        if (M.find(key) == M.end()) {
                            S.pb(new_state);
                            M.insert(key);
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string start;
    while (cin >> start) {
        if (start == "**") break;
        vector<vector<int>> G = {
            {0},
            {0, 0},
            {0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };
        vector<state> S;
        rep(i, 0, 5) {
            string line;
            cin >> line;
            for (int j = 0; j < line.size(); j += 2) {
                if (line[j] != '_') {
                    G[i][j / 2] = encode(line.substr(j, 2)); 
                }
            }
        }
        S.pb(state(G));
        cout << (possible(S, encode(start)) ? "Possible" : "Impossible") << endl;
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
