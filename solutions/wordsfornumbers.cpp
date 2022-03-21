/**
 *  @brief   Kattis - Words for Numbers 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/22/2017
 *  
 *  + Regex
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
#include <regex>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define mp make_pair

string parse(string n) {
    string res;
    if (n.size() == 2) {
        if (n[0] == '1') {
            if (n[1] == '0') return "ten";
            if (n[1] == '1') return "eleven";
            if (n[1] == '2') return "twelve";
            if (n[1] == '3') return "thirteen";
            if (n[1] == '4') return "fourteen";
            if (n[1] == '5') return "fifteen";
            if (n[1] == '6') return "sixteen";
            if (n[1] == '7') return "seventeen";
            if (n[1] == '8') return "eighteen";
            if (n[1] == '9') return "nineteen";
        } else if (n[0] == '2') {
            res = "twenty";
        } else if (n[0] == '3') {
            res = "thirty";
        } else if (n[0] == '4') {
            res = "forty";
        } else if (n[0] == '5') {
            res = "fifty";
        } else if (n[0] == '6') {
            res = "sixty";
        } else if (n[0] == '7') {
            res = "seventy";
        } else if (n[0] == '8') {
            res = "eighty";
        } else if (n[0] == '9') {
            res = "ninety";
        }
        if (n[1] == '0') return res;
        res += '-';
        n.erase(0, 1);
    } else if (n[0] == '0') return "zero";
    if (n[0] == '1') res += "one";
    else if (n[0] == '2') res += "two";
    else if (n[0] == '3') res += "three";
    else if (n[0] == '4') res += "four";
    else if (n[0] == '5') res += "five";
    else if (n[0] == '6') res += "six";
    else if (n[0] == '7') res += "seven";
    else if (n[0] == '8') res += "eight";
    else if (n[0] == '9') res += "nine";
    return res;
}

int main() {
    string s;
    regex e ("[[:d:]]+");
    while (getline(cin, s)) {
        smatch sm;
        set<string> matches;
        string res = s;
        while (regex_search(s, sm, e)) {
            matches.insert(sm[0]);
            s = sm.suffix().str();
        }
        for (string m : matches) {
            res = regex_replace(res, regex(m), parse(m));
        }
        res[0] = toupper(res[0]);
        cout << res << endl;
    }
    return 0;
}
