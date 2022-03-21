/**
 *  @brief   Kattis - A Classy Problem 
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

struct node {
    string s;
    ull rank;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<node> N(n);
        for (auto &node : N) {
            string s, s2;
            cin >> node.s >> s >> s2;
            node.s = node.s.substr(0, node.s.size() - 1);
            istringstream ss(s);
            vector<int> v;
            while (getline(ss, s2, '-')) {
                if (s2 == "upper") v.pb(2);
                else if (s2 == "middle") v.pb(1);
                else v.pb(0);
            }
            node.rank = v.back();
            for (int i = 1; i < 10; ++i) {
                int j = v.size() - i - 1;
                int val = j < 0 ? 1 : v[j];
                node.rank = node.rank * 3 + val; 
            }
        }
        sort(N.begin(), N.end(), [](node &a, node &b) {
            if (a.rank != b.rank) return a.rank > b.rank;
            return a.s < b.s;
        });
        for (auto &node : N) cout << node.s << endl;
        cout << "==============================" << endl;
    }
    return 0;
}

