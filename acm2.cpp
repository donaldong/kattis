/**
 *  @brief   Kattis - Association for Computing Machinery 
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

bool solve(int e, int &t, int &n, int &p) {
    if (t + e <= 300) {
        t += e;
        n++;
        p+= t;
        return true;
    }
    return false;
}

int main() {
    int N, beg;
    cin >> N >> beg;
    vector<int> T(N);
    for (int &e : T) cin >> e;
    int n = 0, t = 0, p = 0;
    if (solve(T[beg], t, n, p)) {
        T.erase(T.begin() + beg);
        sort(T.begin(), T.end());
        for (int i = 0; i < T.size(); ++i) {
            if (!solve(T[i], t, n, p)) break;
        }
    }
    cout << n << " " << p << endl;
    return 0;
}
