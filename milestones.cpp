/**
 *  @brief   Kattis - Milestone Counter 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Brute Force
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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> M >> N;
    vector<ll> T(M), X(N);
    for (ll &t : T) cin >> t;
    for (ll &x : X) cin >> x;
    vector<ll> DT(M-1), DX(N-1);
    rep(i, 0, DT.size()) DT[i] = T[i + 1]  - T[i];
    rep(i, 0, DX.size()) DX[i] = X[i + 1] - X[i];
    ll k = DT[0];
    rep(i, 1, DT.size()) k = gcd(k, DT[i]);
    rep(i, 0, DT.size()) DT[i] /= k;
    set<ll> D;
    rep(i, 0, DX.size() - DT.size() + 1) {
        bool f = true;
        k = DX[i];
        rep(j, 1, DT.size()) k = gcd(k, DX[i + j]);
        rep(j, 0, DT.size()) if (DX[i + j] /k != DT[j]) { 
            f = false;
            break;
        }
        if (f) D.insert(DX[i]);
    }
    cout << D.size() << endl;
    for (ll d : D) cout << d << " ";
    cout << endl;
    return 0;
}
