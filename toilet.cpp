/**
 *  @brief   Kattis - Toilet Seat 
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

int p1(string &s) {
    bool up = s[0] == 'U';
    int res = 0;
    int beg = 1;
    if (!up) { 
        ++res;
        beg = 2;
    }
    for (int i = beg; i < s.size(); i++) {
        if (s[i] == 'D') res += 2;
    }
    return res;
}

int p2(string &s) {
    bool up = s[0] == 'U';
    int res = 0;
    int beg = 1;
    if (up) { 
        ++res;
        beg = 2;
    }
    for (int i = beg; i < s.size(); i++) {
        if (s[i] == 'U') res += 2;
    }
    return res;
}

int p3(string &s) {
    bool up = s[0] == 'U';
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
        bool sup = s[i] == 'U';
        if (up != sup) {
            up = sup;
            res++;
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << p1(s) << endl;
    cout << p2(s) << endl;
    cout << p3(s) << endl;
    return 0;
}
