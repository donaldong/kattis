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

void fix(vector<int> &V, int t) {
    while (!V.empty() && V.back() >= t) {
        V.pop_back();
    }
}

bool get(vector<int> &V, int t) {
    if (V.empty()) return false;
    if (V.back() < t) {
        V.pop_back();
        return true;
    }
    return false;
}

void print(vector<int> &v) {
    for (auto &e : v) cout << e << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> P(N), C(M), S(K);
    rep(i, 0, N) {
        cin >> P[i];
        P[i] *= 2;
        P[i] *= P[i];
    }
    rep(i, 0, M) {
        cin >> C[i];
        C[i] *= 2;
        C[i] *= C[i];
    }
    rep(i, 0, K) {
        cin >> S[i];
        S[i] *= S[i];
        S[i] *= 2;
    }
    sort(P.begin(), P.end());
    sort(C.begin(), C.end());
    sort(S.begin(), S.end());
    int a = N - 1;
    int count = 0;
    while (a >= 0) {
        fix(C, P[a]);
        fix(S, P[a]);
        if (S.empty() && C.empty()) {}
        else if (S.empty()) {
            if (get(C, P[a])) ++count;
        } else if (C.empty()) {
            if (get(S, P[a])) ++count;
        } else {
            if (C.back() <= S.back()) S.pop_back();
            else C.pop_back();
            ++count;
        }
        --a;
    }
    cout << count << endl;
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
