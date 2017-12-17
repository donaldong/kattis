/**
 *  @brief   Kattis - Pig Latin 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/17/2017
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

string solve(string s) {
    string vowels = "aeiouy";
    int j = vowels.find(s[0]);
    if (j >= 0) {
        return s + "yay";
    }
    string res = "";
    int i;
    for (i = 0; i < s.size(); i++) {
        j = vowels.find(s[i]);
        if (j >= 0) break;
        res += s[i];
    }
    i = min((size_t) i, s.size());
    s.erase(0, i);
    return s + res + "ay";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int i = line.find(' ');
        while (i >= 0) {
            cout << solve(line.substr(0, i)) << " ";
            line.erase(0, i+1);
            i = line.find(' ');
        }
        cout << solve(line) << endl;
    }
    return 0;
}
