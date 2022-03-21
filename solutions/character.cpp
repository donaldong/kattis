/**
 *  @brief   Kattis - Character Development 
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
#define mp make_pair

int main() {
    int n;
    cin >> n;
    vector<vector<int>> C(31);
    C[1] = {1, 1};
    for (int i = 2; i < C.size(); ++i) {
        C[i] = vector<int>(C[i - 1].size() + 1);
        for (int j = 1; j < C[i - 1].size(); ++j) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
        C[i][i] = C[i][0] = 1;
    }
    if (n < 2) {
        cout << 0 << endl;
    } else {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res += C[n][i];
        }
        cout << res << endl;
    }
    return 0;
}
