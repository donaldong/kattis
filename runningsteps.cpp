/**
 *  @brief   Kattis - Running Steps 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/26/2017
 *  
 *  + Counting
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair

int main() {
    vector<vector<ull>> C(51);
    C[0] = {1};
    C[1] = {1, 1};
    for (int i = 2; i < C.size(); ++i) {
        C[i] = vector<ull>(i + 1);
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
        C[i][0] = C[i][i] = 1;
    }
    int T;
    cin >> T;
    while (T--) {
        int t;
        cin >> t;
        cout << t << " ";
        int s;
        cin >> s;
        s /= 2;
        int a = s / 3;
        if (s % 3) ++a;
        int b = s / 2;
        ull res = 0;
        for (int i = a; i <= b; ++i) {
            int ones = s - i * 2;
            ull g = C[ones + i][i];
            res += g * g;
        }
        cout << res << endl;
    }
    return 0;
}
