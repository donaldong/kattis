/**
 *  @brief   Kattis - Happy Happy Prime Prime 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Numbers
 *  + Implementation
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

const int N = 10001;
vector<int> H(N, -1);

int sum(int n) {
    string ns = to_string(n);
    int res = 0;
    for (char c : ns) {
        int d = c - '0';
        res += d * d;
    }
    return res;
}

bool happy(int n) {
    n = sum(n);
    if (H[n] != -1) return H[n];
    hset<int> s;
    while (!(n == 1 || s.find(n) != s.end())) {
        s.insert(n);
        n = sum(n);
    }
    bool f = n == 1;
    for (int e : s) H[e] = f;
    H[n] = f;
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> P(N, true);
    P[0] = P[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (!P[i]) continue;
        P[i] = happy(i);
        for (int j = i * i; j <= N; j += i) {
            P[j] = false;
        }
    }
    for (int i = N - 1; i * i > N; --i) {
        if (P[i]) P[i] = happy(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int k, m;
        cin >> k >> m;
        cout << k << " " << m << " " << (P[m] ? "YES" : "NO") << endl;
    }
    return 0;
}
