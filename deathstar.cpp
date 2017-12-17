/**
 *  @brief   Kattis - deathstar 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/16/2017
 *  
 *  + Bit Manipulation
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
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int e;
            cin >> e;
            res[i] |= e;
            res[j] |= e;
        }
    }
    for (auto v : res) cout << v << " ";
    cout << endl;
    return 0;
}
