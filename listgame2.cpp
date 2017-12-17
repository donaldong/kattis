/**
 *  @brief   Kattis - A Different List Game 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/21/2017
 *  
 *  + TAG
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

hmap<ll, int> primeFactors(ll n) {
    hmap<ll, int> f;
    while (n % 2 == 0) {
        f[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            f[i]++;
            n = n/i;
        }
    }
    if (n > 2) f[n]++;
    return f;
}

int count(int n) {
    int i = 1;
    while (n - i >= 0) {
        n -= i;
        ++i;
    }
    return i;
}

int solve(ll n) {
    auto f = primeFactors(n);
    int size = f.size();
    int res = 0;
    for (auto &entry : f) {
        cout << entry.first << " " << entry.second << endl;
        res += count(entry.second);
    }
    return res;
}

int main() {
    ll X;
    cin >> X;
    cout << solve(X) << endl;
    return 0;
}

