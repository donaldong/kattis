/**
 *  @brief   Kattis - Mia 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/18/2017
 *  
 *  + Implementation
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

string solve(int s0, int s1, int r0, int r1) {
    int p1 = score(s0, s1);
    int p2 = score(r0, r1);
    if (p1 == p2) return "Tie.";
    if (p1 > p2) return "Player 1 wins.";
    return "Player 2 wins.";
}

int main() {
    int s0, s1, r0, r1;
    while (cin >> s0 >> s1 >> r0 >> r1) {
        if (!s0 && !s1 && !r0 && !r1) break;
        cout << solve(s0, s1, r0, r1) << endl;
    }
    return 0;
}
