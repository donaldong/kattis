/**
 *  @brief   Kattis - The Owl and the Fox 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        for (int i = n.size() - 1; i >= 0; --i) {
            if (n[i] != '0') {
                --n[i];
                break;
            }
        }
        cout << stoi(n) << endl;
    }
    return 0;
}
