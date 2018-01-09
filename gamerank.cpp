/**
 *  @brief   Kattis - Game Rank 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/07/2018
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
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

int get_stars(int rank) {
    if (rank >= 21 && rank <= 25) return 2;
    if (rank >= 16 && rank <= 20) return 3;
    if (rank >= 11 && rank <= 15) return 4;
    return 5;
}

int bonus(int rank, int consecutive) {
    if (rank < 6) return 0;
    return consecutive >= 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    cin >> line;
    int rank = 25;
    int stars = 0;
    int consecutive = 0;
    bool legend = false;
    for (char c : line) {
        int maxstars = get_stars(rank);
        if (c == 'W') {
            ++consecutive;
            ++stars;
            stars += bonus(rank, consecutive);
            if (stars > maxstars) {
                --rank;
                stars -= maxstars;
            }
            if (rank <= 0) {
                legend = true;
                break;
            }
        } else {
            if (rank <= 20) --stars;
            consecutive = 0;
            if (stars < 0) {
                if (rank < 20) {
                    ++rank;
                    maxstars = get_stars(rank);
                    stars += maxstars;
                } else {
                    stars = 0;
                }
            }
        }
    }
    if (legend) cout << "Legend" << endl;
    else cout << rank << endl;
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
