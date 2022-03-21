/**
 *  @brief   Kattis - Functional Fun 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
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
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define mp make_pair

hmap<string, bool> parse(string line) {
    vector<string> v;
    stringstream ss(line);
    string s;
    while (getline(ss, s, ' ')) {
        v.push_back(s);
    }
    hmap<string, bool> res;
    for (auto i = v.begin() + 1; i != v.end(); ++i) {
        res[*i] = false;
    }
    return res;
}

void step(hmap<string, bool> &d, hmap<string, bool> &cd, string x, string y, bool &in, bool &f) {
    if (!d[x]) d[x] = true;
    else f = false;
    if (!cd[y]) cd[y] = true;
    else in = false;
}

void check(hmap<string, bool> &d, hmap<string, bool> &cd, bool &sur, bool &f) {
    for (auto &entry : cd) {
        if (!entry.second) {
            sur = false;
            break;
        }
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        auto domain = parse(line);
        getline(cin, line);
        auto codomain = parse(line);
        int n;
        cin >> n;
        bool in = true, sur = true, f = true;
        while (n--) {
            string x, y, s;
            cin >> x >> s >> y;
            step(domain, codomain, x, y, in, f);
        }
        check(domain, codomain, sur, f);
        if (in && sur && f) {
            cout << "bijective" << endl;
        } else if (in && f) {
            cout << "injective" << endl;
        } else if (sur && f) {
            cout << "surjective" << endl;
        } else if (f) {
            cout << "neither injective nor surjective" << endl;
        } else {
            cout << "not a function" << endl;
        }
        cin.ignore();
    }
    return 0;
}
