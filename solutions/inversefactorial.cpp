/**
 *  @brief   Kattis - Inverse Factorial 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
 *  
 *  + Numbers
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

int main() {
    string s;
    cin >> s;
    if (s.size() < 4) {
        int x = 1;
        int n = stoi(s);
        for (int i = 1; i < 7; ++i) {
            x *= i;
            if (x == n) {
                cout << i << endl;
                break;
            }
        }
    } else {
        ld n = 0.0;
        for (int i = 1; i <= 1e6; ++i) {
            n += log10(i);
            if (ceil(n) == s.size()) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

