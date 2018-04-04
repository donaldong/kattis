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

bool is_op(string &s) {
    if (s.size() != 1) return false;
    return s[0] == '+' || s[0] == '-' || s[0] == '*';
}

bool eval(string &a, char op, string &b, int &res) {
   try {
       int x = stoi(a);
       int y = stoi(b);
       if (op == '+') res = x + y;
       else if (op == '-') res = x - y;
       else res =  x * y;
       return true;
   } catch (exception& e) { }
   return false;
}

string format(string &a, char op, string &b) {
    string res;
    res += op;
    res += ' ';
    res += a;
    res += ' ';
    res += b;
    return res;
}

string solve(string &line) {
    vector<string> T;
    stringstream ss(line);
    string token;
    while (ss >> token) {
        T.pb(token);
    }
    vector<string> vars;
    for (auto itr = T.rbegin(); itr != T.rend(); ++itr) {
        if (is_op(*itr)) {
            string a = vars.back(); vars.pop_back();
            string b = vars.back(); vars.pop_back();
            int res;
            if (eval(a, (*itr)[0], b, res)) {
                vars.pb(to_string(res));
            } else {
                vars.pb(format(a, (*itr)[0], b));
            }
        } else {
            vars.pb(*itr);
        }
    }
    return vars[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    int t = 1;
    while (getline(cin, line)) {
        cout << "Case " << t++ << ": " << solve(line) << endl;
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
