/**
 *  @brief   Kattis - Engineering English 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/24/2017
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
#include <sstream>
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
    set<string> S;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s;
        while (getline(ss, s, ' ')) {
            string lower = s;
            for (char &c : lower) c = tolower(c);
            if (S.find(lower) == S.end()) {
                S.insert(lower);
                cout << s << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    return 0;
}
