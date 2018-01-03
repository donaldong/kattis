/**
 *  @brief   Kattis - Digital display 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/02/2018
 *  
 *  + Implementation
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

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<string>> m(10);
    for (auto &v : m) v = vector<string>(7);
    m[0][0] = "+---+";
    m[0][1] = "|   |";
    m[0][2] = "|   |";
    m[0][3] = "+   +";
    m[0][4] = "|   |";
    m[0][5] = "|   |";
    m[0][6] = "+---+";

    m[1][0] = "    +";
    m[1][1] = "    |";
    m[1][2] = "    |";
    m[1][3] = "    +";
    m[1][4] = "    |";
    m[1][5] = "    |";
    m[1][6] = "    +";

    m[2][0] = "+---+";
    m[2][1] = "    |";
    m[2][2] = "    |";
    m[2][3] = "+---+";
    m[2][4] = "|    ";
    m[2][5] = "|    ";
    m[2][6] = "+---+";

    m[3][0] = "+---+";
    m[3][1] = "    |";
    m[3][2] = "    |";
    m[3][3] = "+---+";
    m[3][4] = "    |";
    m[3][5] = "    |";
    m[3][6] = "+---+";

    m[4][0] = "+   +";
    m[4][1] = "|   |";
    m[4][2] = "|   |";
    m[4][3] = "+---+";
    m[4][4] = "    |";
    m[4][5] = "    |";
    m[4][6] = "    +";

    m[5][0] = "+---+";
    m[5][1] = "|    ";
    m[5][2] = "|    ";
    m[5][3] = "+---+";
    m[5][4] = "    |";
    m[5][5] = "    |";
    m[5][6] = "+---+";

    m[6][0] = "+---+";
    m[6][1] = "|    ";
    m[6][2] = "|    ";
    m[6][3] = "+---+";
    m[6][4] = "|   |";
    m[6][5] = "|   |";
    m[6][6] = "+---+";

    m[7][0] = "+---+";
    m[7][1] = "    |";
    m[7][2] = "    |";
    m[7][3] = "    +";
    m[7][4] = "    |";
    m[7][5] = "    |";
    m[7][6] = "    +";

    m[8][0] = "+---+";
    m[8][1] = "|   |";
    m[8][2] = "|   |";
    m[8][3] = "+---+";
    m[8][4] = "|   |";
    m[8][5] = "|   |";
    m[8][6] = "+---+";

    m[9][0] = "+---+";
    m[9][1] = "|   |";
    m[9][2] = "|   |";
    m[9][3] = "+---+";
    m[9][4] = "    |";
    m[9][5] = "    |";
    m[9][6] = "+---+";

    auto c = vector<string>(7);
    c[0] = " ";
    c[1] = " ";
    c[2] = "o";
    c[3] = " ";
    c[4] = "o";
    c[5] = " ";
    c[6] = " ";
    string space = "  ";
    while (true) {
        char a = getchar(), b = getchar();
        getchar();
        char d = getchar(), e = getchar();
        getchar();
        if (e < '0' || e > '9') break;
        a -= '0'; b -= '0'; d -= '0'; e -= '0';
        rep(i, 0, 7) {
            print(m[a][i]);
            print(space);
            print(m[b][i]);
            print(space);
            print(c[i]);
            print(space);
            print(m[d][i]);
            print(space);
            print(m[e][i]);
            putchar('\n');
        }
        putchar('\n');
        putchar('\n');
    }
    string end = "end\n";
    print(end);
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
