/**
 *  @brief   Kattis - iBoard 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/23/2017
 *  
 *  + Base Conversion
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

vector<bool> to_bin(char n) {
    vector<bool> res;
    while (n) {
        res.push_back(n % 2);
        n /= 2;
    }
    while (res.size() < 7) {
        res.push_back(0);
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve(char c, bool &left, bool & right) {
    vector<bool> bin = to_bin(c);
    for (auto b : bin) {
        if (b) left = !left;
        else right = !right;
    }
}

bool trapped(bool left, bool right) {
    return left || right;
}

int main() {
    string line;
    while (getline(cin, line)) {
        bool left = false, right = false;
        for (char c : line) {
            solve(c, left, right);
        }
        cout << (trapped(left, right) ? "trapped" : "free") << endl;
    }
    return 0;
}
