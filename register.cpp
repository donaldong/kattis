/**
 *  @brief   Kattis - Primary Register 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/22/2017
 *  
 *  + Counting
 *  + Base Conversion
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
    vector<int> V = {2,3,5,7,11,13,17,19};
    for (int i = 1; i < V.size() - 1; i++) {
        V[i] *= V[i - 1];
    }
    int C = 9699689;
    vector<int> v(V.size());
    for (int &e : v) cin >> e;
    int res = v[0];
    for (int i = 1; i < v.size(); ++i) {
        res += v[i] * V[i - 1];
    }
    cout << C - res << endl;
    return 0;
}
