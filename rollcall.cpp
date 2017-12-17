/**
 *  @brief   Kattis - Roll Call 
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

hmap<string, int> m;

struct p  {
    p(string line) {
        int i = line.find(' ');
        first = line.substr(0, i);
        m[first]++;
        line.erase(0, i + 1);
        last = line;
        f = false;
    }

    string first, last;
    bool f;
};

int main() {
    string line;
    vector<p> v;
    while (getline(cin, line)) {
        v.push_back(p(line));
    }
    sort(v.begin(), v.end(), [](p &a, p &b){
        if (a.last != b.last) {
            return a.last < b.last;
        }
        return a.first < b.first;
    });
    for (size_t i = 0; i < v.size(); ++i) {
        if (m[v[i].first] > 1) v[i].f = true;
    }
    for (auto &p : v) {
        if (p.f) {
            cout << p.first << " " << p.last << endl;
        } else {
            cout << p.first << endl;
        }
    }
    return 0;
}
