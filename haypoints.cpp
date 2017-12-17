/**
 *  @brief   Kattis - Hay Points
 *  @author  Donald Dong (@donaldong)
 *  @date    12/18/2017
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
    int m, n;
    cin >> m >> n;
    hmap<string, int> dict;
    while (m--) {
        string key;
        int value;
        cin >> key >> value;
        dict[key] = value;
    }
    cin.ignore();
    while (n--) {
        string line;
        int res = 0;
        while (getline(cin, line)) {
            if (line == ".") break;
            while (line.size()) {
                int i = line.find(' ');
                res += dict[line.substr(0, i)];
                if (i < 0) break;
                line.erase(0, i + 1);
            }
        }
        cout << res << endl;
    }
    return 0;
}
