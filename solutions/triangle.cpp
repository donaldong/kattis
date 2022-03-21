/**
 *  @brief   Kattis - Sierpiński Circumference 
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
    int n;
    int T = 1;
    while (cin >> n) {
        printf("Case %d: ", T++);
        ld d = (n + 1) * log10(3) - n * log10(2);
        cout << ceil(d) << endl;    
    }
    return 0;
}
