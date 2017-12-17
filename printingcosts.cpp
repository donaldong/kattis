/**
 *  @brief   Kattis - Printing Costs 
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

int main() {
    hmap<char, int> m;
    m[' '] = 0;
    m['&'] = 24;
    m[','] = 7;
    m['2'] = 22;
    m['8'] = 23;
    m['>'] = 10;
    m['D'] = 26;
    m['J'] = 18;
    m['P'] = 23;
    m['V'] = 19;
    m['\\'] = 10;
    m['b'] = 25;
    m['h'] = 21;
    m['n'] = 18;
    m['t'] = 17;
    m['z'] = 19;
    m['!'] = 9;
    m['\''] = 3;
    m['-'] = 7;
    m['3'] = 23;
    m['9'] = 26;
    m['?'] = 15;
    m['E'] = 26;
    m['K'] = 21;
    m['Q'] = 31;
    m['W'] = 26;
    m[']'] = 18;
    m['c'] = 17;
    m['i'] = 15;
    m['o'] =  20;
    m['u'] = 17;
    m['{'] = 18;
    m['\"'] = 6;
    m['('] = 12;
    m['.'] = 4;
    m['4'] = 21;
    m[':'] = 8;
    m['@'] = 32;
    m['F'] = 20;
    m['L'] = 16;
    m['R'] = 28;
    m['X'] = 18;
    m['^'] = 7;
    m['d'] = 25;
    m['j'] = 20;
    m['p'] = 25;
    m['v'] = 13;
    m['|'] = 12;
    m['#'] = 24;
    m[')'] = 12;
    m['/'] = 10;
    m['5'] = 27;
    m[';'] = 11;
    m['A'] = 24;
    m['G'] = 25;
    m['M'] = 28;
    m['S'] = 25;
    m['Y'] = 14;
    m['_'] = 8;
    m['e'] = 23;
    m['k'] = 21;
    m['q'] = 25;
    m['w'] = 19;
    m['}'] = 18;
    m['$'] = 29;
    m['*'] = 17;
    m['0'] = 22;
    m['6'] = 26;
    m['<'] = 10;
    m['B'] = 29;
    m['H'] = 25;
    m['N'] = 25;
    m['T'] = 16;
    m['Z'] = 22;
    m['`'] = 3;
    m['f'] = 18;
    m['l'] = 16;
    m['r'] = 13;
    m['x'] = 13;
    m['~'] = 9;
    m['%'] = 22;
    m['+'] = 13;
    m['1'] = 19;
    m['7'] = 16;
    m['='] = 14;
    m['C'] = 20;
    m['I'] = 18;
    m['O'] = 26;
    m['U'] = 23;
    m['['] = 18;
    m['a'] = 23;
    m['g'] = 30;
    m['m'] = 22;
    m['s'] = 21;
    m['y'] = 24;
    string line;
    while (getline(cin, line)) {
        int res = 0;
        for (char c : line) {
            res += m[c];
        }
        cout << res << endl;
    }
    return 0;
}
