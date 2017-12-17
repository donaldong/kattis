/**
 *  @brief   Kattis - Troll Hunt 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
 *  
 *  + Counting
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
    int b, k, g;
    cin >> b >> k >> g;
    int G = k / g;
    int d = b / G;
    if (b % G > 1) d++;
    if (G == 1) d--;
    cout << d << endl;
    return 0;
}
