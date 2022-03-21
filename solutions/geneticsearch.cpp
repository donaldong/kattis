/**
 *  @brief   Kattis - Genetic Search 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/14/2017
 *  
 *  + Implementation
 *  + String Manipulation
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

bool match(string &s, string &l, int i) {
    if (i + s.size() > l.size()) return false;
    for (int j = 0; j < s.size(); j++) {
        if (s[j] != l[i + j]) return false;
    }
    return true;
}

int type1(string &s, string l) {
    int res = 0;
    for (int i = 0; i < l.size(); i++) {
        if (match(s, l, i)) res++;
    }
    return res;
}

int type2(string &s, string &l) {
    hset<string> strset;
    for (int i = 0; i < s.size(); i++) {
        string ss = s;
        ss.erase(i, 1);
        strset.insert(ss);
    }
    int res = 0;
    for (string str : strset) {
        res += type1(str, l);
    }
    return res;
}

int type3(string &s, string l) {
    string opt = "ATCG";
    hset<string> strset;
    for (int i = 0; i <= s.size(); i++) {
        for (char c : opt) {
            string ss = s.substr(0, i);
            ss += c;
            ss += s.substr(i, s.size() - i);
            strset.insert(ss);
        }
    }
    int res = 0;
    for (string str : strset) {
        res += type1(str, l);
    }
    return res;
}

int main() {
    string s, l;
    while (cin >> s >> l) {
        printf("%d %d %d\n", type1(s, l), type2(s, l), type3(s, l));
    }
    return 0;
}
