/**
 *  @brief   Kattis - Conformity 
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

string to_string(vector<int> &v) {
    string res = "";
    for (int e : v) res += to_string(e) + ",";
    return res;
}

int main() {
    int n;
    cin >> n;
    hmap<string, int> p;
    int max_p = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> course(5);
        for (int &e : course) cin >> e;
        sort(course.begin(), course.end());
        string key = to_string(course);
        p[key]++;
        max_p = max(max_p, p[key]);
    }
    int res = 0;
    for (auto entry : p) {
        if (entry.second == max_p) {
            res += max_p;
        }
    }
    cout << res << endl;
    return 0;
}
