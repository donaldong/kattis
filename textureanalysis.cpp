/**
 *  @brief   Kattis - Texture Analysis 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2018
 *  
 *  + Implementation
 */

#include <algorithm>
//#include <bits/stdc++.h>
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

void scan(ll &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c >= '0' && c <= '9'); c=getchar()) number = number *10 + c - '0';
    if (negative) number *= -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    ll i = 1;
    while (getline(cin, line)) {
        if (line == "END") break;
        bool even = true;
        size_t d = line.find('*', 1);
        for (size_t i = 0; i < line.size(); i += d) {
            if (line[i] != '*') {
                even = false;
                break;
            }
        }
        if (even) {
            for (size_t i = 0; i < line.size(); ++i) {
                if (i % d && line[i] != '.') {
                    even = false;
                    break;
                }
            }
        }
        cout << i++ << " " << (even ? "EVEN" : "NOT EVEN") << endl;
    }
    return 0;
}
