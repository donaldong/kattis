/**
 *  @brief   Kattis - Eb Alto Saxophone Player 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/20/2017
 *  
 *  + Implementation
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

void solve(vector<bool> &f, vector<int> &v, vector<int> b) {
    hset<int> used;
    for (int i = 0; i < b.size(); i += 2) {
        for (int j = b[i]; j <= b[i + 1]; ++j) {
            used.insert(j - 1);
        }
    }
    for (int i = 0; i < f.size(); i++) {
        if (used.find(i) == used.end()) {
            f[i] = false;
        }
    }
    for (int i : used) {
        if (!f[i]) {
            f[i] = true;
            v[i]++;
        }
    }
}

void solve(char c, vector<bool> &f, vector<int> &v) {
    if (c == 'c') {
        solve(f, v, {2, 4, 7, 10});
    }
    else if (c == 'd') {
        solve(f, v, {2, 4, 7, 9});
    }
    else if (c == 'e') {
        solve(f, v, {2, 4, 7, 8});
    }
    else if (c == 'f') {
        solve(f, v, {2, 4, 7, 7});
    }
    else if (c == 'g') {
        solve(f, v, {2, 4});
    }
    else if (c == 'a') {
        solve(f, v, {2, 3});
    }
    else if (c == 'b') {
        solve(f, v, {2, 2});
    }
    else if (c == 'C') {
        solve(f, v, {3, 3});
    }
    else if (c == 'D') {
        solve(f, v, {1, 4, 7, 9});
    }
    else if (c == 'E') {
        solve(f, v, {1, 4, 7, 8});
    }
    else if (c == 'F') {
        solve(f, v, {1, 4, 7, 7});
    }
    else if (c == 'G') {
        solve(f, v, {1, 4});
    }
    else if (c == 'A') {
        solve(f, v, {1, 3});
    }
    else if (c == 'B') {
        solve(f, v, {1, 2});
    }
}

string solve(string &s) {
    string res = "";
    vector<int> v(10, 0);
    vector<bool> f(10, false);
    for (char c : s) {
        solve(c, f, v);
    }
    for (int e : v) {
        res += to_string(e) + " ";
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }
    return 0;
}
