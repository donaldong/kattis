/**
 *  @brief   Kattis - Variable Arithmetic 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/21/2017
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

int main() {
    string line;
    hmap<string, int> V;
    while (getline(cin, line)) {
        if (line == "0") break;
        int eq = line.find('=');
        if (eq > 1) {
            string var = line.substr(0, eq - 1);
            string val = line.substr(eq + 2, line.size() - eq);
            V[var] = stoi(val);
        } else {
            int res = 0;
            bool f = false;
            vector<string> v;
            string plus = " + ";
            while (line.size()) {
                int i = line.find(plus);
                string var;
                if (i < 0) { 
                    var = line;
                    line = "";
                } else {
                    var = line.substr(0, i);
                    line.erase(0, i + plus.size());
                }
                if (var[0] >= '0' && var[0] <= '9') {
                    f = true;
                    res += stoi(var);
                } else if (V.find(var) != V.end()) {
                    f = true;
                    res += V[var];
                } else {
                    v.push_back(var);
                }
            }
            if (!v.size()) {
                cout << res << endl;
                continue;
            }
            if (f) cout << res << plus;
            for (int i = 0; i < v.size() - 1; ++i) {
                cout << v[i] << plus;
            }
            cout << v.back() << endl;
        }
    }
    return 0;
}
