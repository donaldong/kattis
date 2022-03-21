/**
 *  @brief   Kattis - Game of Throwns 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/19/2017
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
    int n, k;
    cin >> n >> k;
    vector<int> h;
    int t = 0;
    h.push_back(t);
    while (k--) {
        string command;
        cin >> command;
        if (command == "undo") {
            int x;
            cin >> x;
            while (x--) {
                h.pop_back();
            }
            t = h.back();
        } else {
            int x = stoi(command);
            t += x;
            while (t >= n) t -= n;
            while (t < 0) t += n;
            h.push_back(t);
        }
    }
    cout << t << endl;
    return 0;
}
