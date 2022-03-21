/*q
 *  @brief   Kattis - Meow Factor 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Numbers
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

hmap<ull, int> prime_factors(ull n) {
    hmap<ull, int> F;
    while (n % 2 == 0) {
        n /= 2;
        ++F[2];
    }
    for (ull i = 3; pow(i, 9) <= n; i += 2) {
        while (n % i == 0) {
             n /= i;
             ++F[i];
        }
    }
    if (n > 2) ++F[n];
    return F;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull n;
    cin >> n;
    auto F = prime_factors(n);
    ull res = 1;
    for (auto entry : F) {
        if (entry.second >= 9) {
            int k = entry.second / 9;
            res *= pow(entry.first, k);
        }
    }
    cout << res << endl;
    return 0;
}
