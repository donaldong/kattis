/**
 *  @brief   Kattis - Doorman 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/20/2017
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

int diff(string &s, int i, int &w, int &m) {
    if (s[i] == 'W') w++;
    else m++;
    return abs(w - m);
}

int swap(string &s, int i, int &w, int &m) {
    if (s[i] == 'W') w--;
    else m--;
    swap(s[i], s[i+1]);
    return diff(s, i, w, m);
}

int main() {
    int x;
    cin >> x;
    string line;
    cin >> line;
    int w = 0, m = 0;
    int count = 0;
    for (int i = 0; i < line.size(); i++) {
        if (diff(line, i, w, m) > x) {
            if (swap(line, i, w, m) > x) {
                break;
            }
        }
        count++;
    }
    cout << count << endl;
    return 0;
}
