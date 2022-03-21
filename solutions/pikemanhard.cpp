/**
 *  @brief   Kattis - A Vicious Pikeman (Hard) 
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
    ll N, T, A, B, C, t;
    cin >> N >> T >> A >> B >> C >> t;
    vector<ll> P(C + 1, -1);
    size_t size = 0;
    while (size < N) {
        if (P[t] != -1) break;
        P[t] = size;
        t = (A * t + B) % C + 1;
        ++size;
    }
    ll o = P[t] == -1 ? size : P[t];
    ll L = size - o;
    ll a = size - L;
    ll b = L == 0 ? 0 : (N - a) / L;
    ll r = L == 0 ? 0 : (N - a) % L;
    vector<ll> v(L, b - 1);
    for (size_t i = 0; i < r; ++i) {
        ++v[i];
    }
    size_t n = 0;
    ll p = 0;
    t = 0;
    for (size_t i = 1; i <= C; ++i) {
        if (P[i] == -1) continue;
        if (t + i > T) break;
        n++;
        p = (p + i + t) % M;
        t += i;
        ll index = P[i];
        if (index >= o && v[index - o] > 0) {
            ll count = min(v[index - o], (ll)((T - t) / i));
            if (count <= 0) continue;
            count %= M;
            n += count;
            p += (((t + i) % M * count) % M + ((count * (count - 1) / 2) % M * i) % M) % M;
            p %= M;
            t += count * i;
        }
    }
    cout << n << " " << p << endl; 
    return 0;
}
