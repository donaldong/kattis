/**
 *  @brief   Kattis - Qanat 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/27/2017
 *  
 *  + Geometry
 *  + Binary Search
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

const ld D = 1e-5;

void print(ld n) {printf("%.4Ld\n", n);

ld cost(vector<ld> &X, ld w, ld k) {
    X.push_back(w);
    ld res = X[0] + k * X[0];
    res = res * res / 4;
    for (size_t i = 1; i < X.size(); ++i) {
        ld b = k * X[i-1];
        ld t = b + k * X[i] + X[i] - X[i - 1];
        res += t * t / 4;
        res -= b * b / 2;
    }
    X.pop_back();
    return res;
}

// hmmm maybe Gradient Descent? 
ld search(vector<ld> &X, ld w, ld k) {
    ld a = 0, b = w;
    ld c = w;
    auto x = scale(X, c);
    x.push_back(c);
    ld nC = cost(x, w, k);
    ld C = 0.0;
    ld diff = nC;
    while (abs(diff) >= D) {
        if (diff < 0) b = c;
        else a = c;
        diff = nC - C;
        C = nC;
        x = scale(X, c);
        nC = cost(x, w, k);
    }
}

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    ld k = h; k /= w;
    vector<ld> X;
    while (X.size() < n) {
        ld x = search(X, w, k);
        X.push_back(x);
    }
    print(cost(X, w, k));
    for (size_t i = 0; i < X.size(); ++i) {
        if (i >= 10) break;
        print(X[i]);
    }
    return 0;
}
