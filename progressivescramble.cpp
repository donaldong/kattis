/**
 *  @brief   Kattis - Progressive Scramble 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/17/2017
 *  
 *  + Implementation
 *  + Encryption
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

vector<int> value(string &line) {
    vector<int> v;
    for (char c : line) {
        if (c == ' ') v.push_back(0);
        else v.push_back(c - 'a' + 1);
    }
    return v;
}

string to_string(vector<int> &u) {
    string res = "";
    for (int e : u) {
        if (e == 0) res += ' ';
        else res += 'a' + e - 1;
    }
    return res;
}

string encode(string &line) {
    auto v = value(line);
    vector<int> u(v.size());
    u[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
        u[i] = (v[i] + u[i-1]) % 27;
    }
    return to_string(u);
}

string decode(string &line) {
    auto u = value(line);
    for (int i = 1; i < u.size(); i++) {
        while (u[i] < u[i - 1]) u[i] += 27;
    }
    for (int i = u.size() - 1; i > 0; i--) {
        u[i] -= u[i-1];
    }
    return to_string(u);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        char op = line[0];
        line.erase(0, 2);
        if (op == 'e') cout << encode(line) << endl;
        else cout << decode(line) << endl;
    }
    return 0;
}
