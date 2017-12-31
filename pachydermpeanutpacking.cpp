/**
 *  @brief   Kattis - Pachyderm Peanut Packing 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/29/2017
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

struct box {
    ld x1, x2, y1, y2;
    string s;

    bool in(ld x, ld y) {
        return x <= x2 && x >= x1 && y <= y2 && y >= y1;
    }
};

string solve(vector<box> &B, ld x, ld y, string &s) {
    for (auto &b : B) {
        if (b.in(x, y)) {
            if (s == b.s) return "correct";
            return b.s;
        }
    }
    return "floor";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (!n) break;
        vector<box> B(n);
        for (auto &b : B) {
            cin >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> b.s;
        }
        int m;
        cin >> m;
        rep(i, 0, m) {
            ld x, y;
            string s;
            cin >> x >> y >> s;
            cout << s << " " << solve(B, x, y, s) << endl;
        }
        cout << endl;
    }
    return 0;
}
