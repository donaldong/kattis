/**
 *  @brief   Kattis - N-Puzzle 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/27/2017
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
#define mp make_pair

int main() {
    string g;
    for (int i = 0; i < 4; ++i) {
        string l;
        cin >> l;
        g += l;
    }
    string s = "ABCDEFGHIJKLMNO";
    int res = 0;
    for (int i = 0; i < g.size(); ++i) {
        if (g[i] == '.') continue;
        int j = s.find(g[i]);
        res += abs(i%4 - j%4) + abs(i/4 - j/4);
    }
    cout << res << endl;
    return 0;
}
