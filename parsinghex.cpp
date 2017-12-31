/**
 *  @brief   Kattis - Parsing Hex 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
 *  
 *  + Base Conversion
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

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

bool digit(char c) {
    if (c <= '9' && c >= '0') return true;
    char cc = tolower(c);
    return cc >= 'a' && cc <= 'f';
}

int convert(char c) {
    if (c <= '9' && c >= '0') return c - '0';
    char cc = tolower(c);
    return cc - 'a' + 10;
}

ll convert(string s) {
    ll res = 0;
    for (char c : s) {
        res = res * 16 + convert(c);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        vector<string> hex;
        while (line.size()) {
            auto i = line.find("0x");
            auto j = line.find("0X");
            i = min(i, j);
            if (i == string::npos) break;
            else {
                string s;
                line.erase(0, i);
                int l = 2;
                rep(i, 2, line.size()) {
                    if (!digit(line[i])) break;
                    ++l;
                }
                hex.pb(line.substr(0, l));
                line.erase(0, l);
            }
        }
        for (string &s : hex) {
            cout << s << " " << convert(s.substr(2, s.size() - 2)) << endl;
        }
    }
    return 0;
}
