/**
 *  @brief   Kattis - Interesting Integers 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
 *  
 *  + Numbers
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

ld sqrt5 = sqrt(5);
ld P = (1.0 + sqrt5) / 2.0;
ld p = (1.0 - sqrt5) / 2.0;
hmap<uint, uint> F;

uint f(uint n) {
    if (F.find(n) != F.end()) return F[n];
    uint res = (pow(P, n) - pow(p, n)) / sqrt5;
    F[n] = res;
    return res;
}

uint G(uint n, uint a1, uint a2) {
    return f(n - 2) * a1 + f(n - 1) * a2;
}

bool isPerfectSquare(int x) {
    int s = sqrt(x);
    return s * s == x;
}

uint getN(uint f) {
    return log(f * sqrt5 + sqrt(5 * f * f - 4.0))/log(p);
}
 
bool possible(uint a1, uint a2, uint n) {
    for (int i = 3; i < 50; ++i) {
        uint res = G(i, a1, a2);
        if (res == n) return true;
        if (res > n) break;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        uint a1 = 1, a2 = 1;
        while (!possible(a1, a2, n)) {
            if (a1 < a2) ++a1;
            else { 
                ++a2;
                a1 = 1;
            }
        }
        cout << a1 << " " << a2 << endl;
    }
    return 0;
}
