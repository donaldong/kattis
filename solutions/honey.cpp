/**
 *  @brief   Kattis - Honeycomb Walk 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/27/2017
 *  
 *  + Counting
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
#define mp make_pair

vector<int> DX = {0, 0, 1, -1, 1, 1};
vector<int> DY = {1, -1, 0, 0, 1, -1};

struct node {
    int s = 0;
    int x = 0;
    int y = 0;
    node() {}
    node(int s, int x, int y) : s(s), x(x), y(y) {}
};

vector<ull> F(15);

ull solve(int n) {
    ull res = 0;
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n - a; ++b) {
            for (int c = 0; c <= n - a - b; ++c) {
                for (int d = 0; d <= n - a - b - c; ++d) {
                    for (int e = 0; e <= n - a - b - c - d; ++e) {
                        int f = n - a - b - c - d - e;
                        if (c - d + e -f == 0 && a - b + e - f == 0) {
                            ull t = F[n];
                            t /= F[a];
                            t /= F[b];
                            t /= F[c];
                            t /= F[d];
                            t /= F[e];
                            t /= F[f];
                            res += t;
                        }
                    }
                }
            }
        }
    }
    return res;
}

vector<ull> solve() {
    auto res = vector<ull>(14);
    for (int i = 0; i < 14; ++i) {
        res[i] = solve(i + 1);
    }
    return res;
}

int main() {
    F[0] = 1;
    for (int i = 1; i <= 14; ++i) {
        F[i] = i * F[i - 1];
    }
    auto res = solve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << res[n - 1] << endl;
    }
    return 0;
}
