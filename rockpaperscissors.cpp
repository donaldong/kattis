/**
 *  @brief   Kattis - Rock-Paper-Scissors Tournament 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/27/2017
 *  
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
#define mp make_pair

bool win(string &a, string &b) {
    if (a == "rock" && b == "scissors") return true;
    if (a == "scissors" && b == "paper") return true;
    return a == "paper" && b == "rock";
}

struct player {
    int w = 0, l = 0;
};

void solve(int p1, string &m1, int p2, string &m2, vector<player> &P) {
    auto a = &P[p1 - 1];
    auto b = &P[p2 - 1];
    if (win(m1, m2)) {
        a->w++;
        b->l++;
    } else if (win(m2, m1)) {
        a->l++;
        b->w++;
    }
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (n == 0) break;
        vector<player> P(n);
        int total = k * n * (n - 1) / 2;
        for (int i = 0; i < total; ++i) {
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;
            solve(p1, m1, p2, m2, P);
        }
        for (auto &p : P) {
            if (!p.w && !p.l) {
                cout << '-' << endl;
                continue;
            }
            printf("%.3Lf\n", ld(p.w) / (p.w + p.l));
        }
        cout << endl;
    }
    return 0;
}
