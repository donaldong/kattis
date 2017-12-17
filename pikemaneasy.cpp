/**
 *  @brief   Kattis - A Vicious Pikeman (Easy) 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/19/2017
 *  
 *  + Modular
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

const int M = 1000000007;

int main() {
    ull N, T, A, B, C, t;
    cin >> N >> T >> A >> B >> C >> t;
    vector<ull> P;
    P.push_back(t);
    while (P.size() != N) {
        P.push_back((A * P.back() + B) % C + 1);
    }
    sort(P.begin(), P.end());
    int n = 0;
    ull p = 0;
    t = 0;
    for (size_t i = 0; i < P.size(); ++i) {
        if (t + P[i] > T) break;
        n++;
        p = (p + P[i] + t) % M;
        t += P[i];
    }
    cout << n << " " << p << endl; 
    return 0;
}
