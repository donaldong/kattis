/**
 *  @brief   Kattis - Word Cloud 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/21/2017
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

struct word {
    int l, c, p, w;
};

int main() {
    int W, N;
    int T = 1;
    while (cin >> W >> N) {
        if (!W && !N) break;
        cout << "CLOUD " << T++ << ": ";
        vector<word> words(N);
        int C = 0;
        for (auto &w : words) {
            string word;
            cin >> word >> w.c;
            w.l = word.length();
            C = max(C, w.c);
        }
        for (auto &w : words) {
            w.p = 8 + ceil(40.0 * (w.c - 4.0) / (C - 4.0));
            w.w = ceil(9.0 / 16.0 * w.l * w.p);
        }
        int width = 0, height = 0, ch = 0;
        for (auto &w : words) {
            if (width + w.w <= W) {
                width += w.w + 10;
                ch = max(ch, w.p);
            } else {
                width = w.w + 10;
                height += ch;
                ch = w.p;
            }
        }
        cout << height + ch << endl;
    }
    return 0;
}
