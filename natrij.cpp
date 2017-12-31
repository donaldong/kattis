/**
 *  @brief   Kattis - Natrij 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/30/2017
 *  
 *  + Implementation
 *  + Bad Description
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

vector<int> parse(stringstream &ss) {
    vector<int> res;
    string s;
    while(getline(ss, s, ':')) {
        res.pb(stoi(s));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    stringstream sa(a), sb(b);
    auto x = parse(sb);
    auto y = parse(sa);
    x[2] -= y[2];
    if (x[2] < 0) {
        x[2] += 60;
        --x[1];
    }
    x[1] -= y[1];
    if (x[1] < 0) {
        x[1] += 60;
        --x[0];
    }
    x[0] -= y[0];
    if (x[0] < 0) x[0] += 24;
    if (x[0] == x[1] && x[1] == x[2] && x[2] == 0) x[0] = 24;
    printf("%02d:%02d:%02d\n", x[0], x[1], x[2]);
    return 0;
}
