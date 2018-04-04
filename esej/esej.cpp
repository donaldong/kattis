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

bool valid(vector<string> &V, int A, int B) {
    if (V.size() > B) return false;
    if (V.size() < A) return false; 
    hset<string> S;
    for (auto &s : V) {
        S.insert(s);
        if (s.size() == 0) return false;
        if (s.size() > 15) return false;
    }
    int n = B / 2;
    if (B & 1) ++n;
    return S.size() >= n;
}

bool test(string s, int A, int B) {
    stringstream ss(s);
    string token;
    vector<string> V;
    while (ss >> token) {
        V.pb(token);
    }
    return valid(V, A, B);
}

void test() {
    cout << test("dobar je ovaj marko marulic", 2, 7) << endl;
    cout << test("nama je profesor reko da to ne treba za lektiru al onda je bila buka i nisam ga cuo pa jel bi mi mogli dat bodove", 26, 30) << endl; 
    cout << test("konzekvence pojmovnoga diskursa u predstavljenoj noveli naizgled ne odrazavaju paradigmatske tendencije tipoloske klasifikacije iako su stilski i didakticki opravdane", 19, 19) << endl;
}

vector<string> build(int n) {
    vector<string> Q;
    rep(i, 0, 26) {
        char c = 'a' + i;
        string s;
        s += c;
        Q.pb(s);
        if (Q.size() == n) return Q;
    }
    auto Q1 = Q;
    while (true) {
        vector<string> Q2;
        rep(i, 0, Q1.size()) {
            rep(j, 0, 26) {
                char c = 'a' + j % 26;
                string s = Q1[i] + c;
                Q2.pb(s);
                Q.pb(s);
                if (Q.size() == n) return Q;
            }
        }
        Q1 = Q2;
    }
    return Q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    int n = B / 2;
    if (B & 1) ++n;
    int cur = 0;
    auto Q = build(n);
    while (Q.size() < A) {
        Q.pb(Q[0]);
    }
    for (auto &q : Q) cout << q << " ";
    cout << endl;
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
