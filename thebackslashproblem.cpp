/**
 *  @brief   Kattis - The Backslash Problem 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/17/2017
 *  
 *  + Implementation
 *  + Recursion
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

bool special(char c) {
    if (c == '\\') return true;
    if (c >= '!' && c <= '*') return true;
    if (c >= '[' && c <= ']') return true;
    return false;
}

string solve(int n, string &str) {
    if (n == 0) return str;
    string res = "";
    for (char c : str) {
        if (special(c)) res += '\\';
        res += c;
    }
    return solve(n-1, res);
}

int main() {
    string n;
    string str;
    while (getline(cin, n)) {
        getline(cin, str);
        cout << solve(stoi(n), str) << endl;
    }
    return 0;
}
