/**
 *  @brief   Kattis - Permutation Encryption 
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
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> K(n);
        for (auto &e : K) { cin >> e; --e; }
        cin.ignore();
        string msg;
        getline(cin, msg);
        int r = msg.size() / K.size();
        if (msg.size() % K.size()) ++r;
        while (msg.size() != r * K.size()) msg += ' ';
        string res;
        rep(i, 0, r) {
            for (int k : K) {
                res += msg[i * K.size() + k]; 
            }
        }
        cout << "'" << res << "'" << endl;
    }
    return 0;
}
