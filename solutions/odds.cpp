/**
 *  @brief   Kattis - Odds of Mia 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/22/2017
 *  
 *  + Counting
 *  + Probability
 *  + Brute Force
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

int score(int s0, int s1) {
    int a = min(s0, s1);
    int b = max(s0, s1);
    if (a == 1 && b == 2) return INT_MAX;
    if (a == b) return a * 100 + b * 10;
    return b * 10 + a;
}

void build(vector<vector<int>> &opts) {
    if (opts.size() == 0) {
        opts.push_back({1});
        opts.push_back({2});
        opts.push_back({3});
        opts.push_back({4});
        opts.push_back({5});
        opts.push_back({6});
        return;
    }
    int size = opts.size();
    for (int i = 2; i <= 6; ++i) {
        for (int j = 0; j < size; ++j) {
            opts.push_back(opts[j]);
            opts.back().push_back(i);
        }
    }
    for (int i = 0; i < size; ++i) {
        opts[i].push_back(1);
    }
}

void build(vector<vector<int>> &opts, char c) {
    int v = c - '0';
    if (opts.size() == 0) {
         opts.push_back({v});
         return;
    }
    for (int i = 0; i < opts.size(); ++i) {
        opts[i].push_back(v);
    }
}

void solve(vector<int> &v, int &win) {
    int p1 = score(v[0], v[1]);
    int p2 = score(v[2], v[3]);
    if (p1 > p2) win++;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void display(int win, int total) {
    if (win == 0) {
        cout << 0 << endl;
    } else if (win == total) {
        cout << 1 << endl;
    } else {
        int d = gcd(win, total);
        cout << win/d << "/" << total/d << endl;
    }
}

int main() {
    char s0, s1, r0, r1;
    while (cin >> s0 >> s1 >> r0 >> r1) {
        if (s0 == '0' && s1 == '0' && r0 == '0' && r1 == '0') break;
        vector<vector<int>> opts;
        if (s0 == '*') build(opts);
        else build(opts, s0);
        if (s1 == '*') build(opts);
        else build(opts, s1);
        if (r0 == '*') build(opts);
        else build(opts, r0);
        if (r1 == '*') build(opts);
        else build(opts, r1);
        int win = 0;
        for (auto v : opts) {
            solve(v, win);
        }
        display(win, opts.size());
    }
    return 0;
}
