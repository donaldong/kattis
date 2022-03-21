/**
 *  @brief   Kattis - Egypt 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/26/2017
 *  
 *  + Geometry
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
#define mp make_pair

bool valid(int a, int b, int c) {
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    return v[0] * v[0] + v[1] * v[1] == v[2] * v[2];
}

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (!a && !b && !c) break;
        cout << (valid(a, b, c) ? "right" : "wrong") << endl; 
    }
    return 0;
}
