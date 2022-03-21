/**
 *  @brief   Kattis - Linden Mayor System 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
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

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    hmap<char, string> M;
    while (n--) {
        char a;
        string junk, b;
        cin >> a >> junk >> b;
        M[a] = b;
    }
    string s;
    cin >> s;
    while (m--) {
        string res;
        for (char c : s) {
            if (M.find(c) != M.end()) res += M[c];
            else res += c;
        }
        s = res;
    }
    cout << s << endl;
    return 0;
}
