/**
 *  @brief   Kattis - Exam Redistribution 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/23/2017
 *  
 *  + Permutation
 *  + Brute Force
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

int pop(hmap<int, vector<int>> &m, int v) {
    auto i = m.find(v);
    auto j = i->second.back();
    i->second.pop_back();
    if (!i->second.size()) {
        m.erase(i);
    }
    return j + 1;
}

bool possible(vector<int> &s) {
    int res = 0;
    for (int i = 1; i < s.size(); ++i) {
        res += s[i];
    }
    return s[0] <= res;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    hmap<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        m[s[i]].push_back(i);
    }
    sort(s.rbegin(), s.rend());
    if (!possible(s)) cout << "impossible" << endl;
    else {
        for (int e : s) {
            cout << pop(m, e) << " ";
        }
        cout << endl;
    }
    return 0;
}

