/**
 *  @brief   Kattis - Busy Schedule 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/24/2017
 *  
 *  + Base Conversion
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

int getkey(string t0, string &t1) {
    int h, m;
    int i = t0.find(':');
    h = stoi(t0.substr(0, i));
    t0.erase(0, i + 1);
    m = stoi(t0);
    if (t1 == "p.m." && h != 12) h += 12;
    else if (t1 == "a.m." && h == 12) h = 0;
    return h * 60 + m; 
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cin.ignore();
        map<int, vector<string>> m;
        while (n--) {
            string t0, t1;
            cin >> t0 >> t1;
            m[getkey(t0, t1)].push_back(t0 + " " + t1);
        }
        for (auto &entry : m) {
            for (auto &s : entry.second) {
                cout << s << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
