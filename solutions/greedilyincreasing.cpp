/**
 *  @brief   Kattis - Greedily Increasing Subsequence 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/18/2017
 *  
 *  + Subsequence
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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> res(n);
    for (int &e : v) {
        cin >> e;
    }
    int c = 0;
    res[0] = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] > res[c]) {
            res[++c] = v[i];
        }
    }
    cout << c + 1 << endl;
    for (int i = 0; i <= c; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
