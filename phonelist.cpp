/**
 *  @brief   Kattis - Phone List 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/21/2017
 *  
 *  + Brute Force
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define mp make_pair

bool valid(hset<string> &s) {
    for (auto &e : s) {
        for (int i = 1; i < e.length(); ++i) {
            if (s.find(e.substr(0, i)) != s.end()) return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        hset<string> s;
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            s.insert(str);
        }
        cout << (valid(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
