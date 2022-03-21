/**
 *  @brief   Kattis - Rečenice 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/08/2018
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

vector<string> one = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> ten = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                        "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> hundreds = {"onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", 
                        "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};

string parse(string s) {
    string res = "";
    if (s.size() == 3) {
        res += hundreds[s[0] - '1'];
        s.erase(0, 1);
    }
    if (s.size() == 2) {
        if (s[0] == '0') {
            s.erase(0, 1);
        } else if (s[0] == '1') {
            res += ten[s[1] - '0'];
            s.clear();
        } else {
            res += tens[s[0] - '2'];
            s.erase(0, 1);
        }
    }
    if (s.size() == 1) {
        if (s[0] != '0') res += one[s[0] - '1'];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mark = 0;
    int total = 0;
    vector<string> V(n), M(1000);
    rep(i, 1, M.size()) {
        M[i] = parse(to_string(i));
    }
    rep(i, 0, n) {
        cin >> V[i];
        if (V[i] == "$") mark = i;
        else total += V[i].size();
    }
    string res;
    rep(i, 1, M.size()) {
        if (M[i].size() + total == i) {
            res = M[i];
            break;
        }
    }
    rep(i, 0, n - 1) {
        if (V[i] == "$") cout << res << " ";
        else cout << V[i] << " ";
    }
    if (V.back() == "$") cout << res << endl; 
    else cout << V.back() << endl;
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
