/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    03/23/2018
 *  
 *  + Brute Force
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

void display(hmap<string, hset<string>> &F, hmap<string, hset<string>> &E) {
    vector<pair<string, string>> res;
    for (auto &f : F) {
        for (auto &e : f.second) {
            if (E[e].find(f.first) == E[e].end()) continue;
            res.pb(mp(f.first, e));
        }
    }
    sort(res.begin(), res.end());
    for (auto &p : res) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        hmap<string, hset<string>> F, E; // foreign, english
        rep(i, 0, N) {
            string t;
            cin >> t;
            int M;
            cin >> M;
            hset<string> A, B;
            rep(j, 0, M) {
                cin >> t;
                A.insert(t);
            }
            cin >> M;
            rep(j, 0, M) {
                cin >> t;
                B.insert(t);
            }
            for (string s : A) {
                if (F.find(s) != F.end()) {
                    if (F[s].empty()) continue;
                    hset<string> S;
                    for (string b : B) {
                        if (F[s].find(b) != F[s].end()) 
                            S.insert(b);
                    }
                    F[s] = S;
                } else {
                    F[s] = B;
                }
            }
            for (string s : B) {
                if (E.find(s) != E.end()) {
                    if (E[s].empty()) continue;
                    hset<string> S;
                    for (string a : A) {
                        if (E[s].find(a) != E[s].end()) 
                            S.insert(a);
                    }
                    E[s] = S;
                } else {
                    E[s] = A;
                }
            }
        }
        display(F, E);
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
