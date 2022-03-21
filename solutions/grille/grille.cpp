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

bool fill(vector<string> &res, vector<vector<bool>> &G, string s) {
    int k = 0;
    rep(i, 0, G.size()) {
        rep(j, 0, G[i].size()) {
            if (G[i][j]) {
                if (res[i][j] != ' ') { return false; }
                res[i][j] = s[k++];
            }
        }
    }
    return true; 
}

void rotate(vector<vector<bool>> &mat) {
    int N = mat.size();
    for (int x = 0; x < N / 2; x++) {
        for (int y = x; y < N-x-1; y++) {
            // store current cell in temp variable
            bool temp = mat[x][y];

            // move values from left to top
            mat[x][y] = mat[N-1-y][x];

            // move values from bottom to left
            mat[N-1-y][x] = mat[N-1-x][N-1-y];

            // move values from right to bottom
            mat[N-1-x][N-1-y] = mat[y][N-1-x];

            mat[y][N-1-x] = temp;
        }
    }
}

bool solve(string &word, vector<vector<bool>> &G, vector<string> &res, int k) {
    rep(i, 0, 4) {
        if (!fill(res, G, word.substr(0, k))) return false;
        rotate(G);
        word.erase(0, k);
    }
    for (auto &s : res) {
        for (char c : s) if (c == ' ') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<bool>> G(n, vector<bool>(n));
    int k = 0;
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, n) {
            if (s[j] == '.') {
                G[i][j] = true;
                ++k;
            } else G[i][j] = false;
        }
    }
    string word;
    cin >> word;
    vector<string> res(n, string(n, ' '));
    if (solve(word, G, res, k)) {
        for (auto &s : res) cout << s;
        cout << endl;
    } else {
        cout << "invalid grille" << endl;
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
