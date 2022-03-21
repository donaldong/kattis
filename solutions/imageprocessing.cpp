/**
 *  @brief   Kattis - Image Processing 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/18/2017
 *  
 *  + Implementation
 *  + Matrix
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

int solve(vector<vector<int>> &img, vector<vector<int>> &k, int r, int c) {
   int res = 0;
   for (int i = 0; i < k.size(); i++) {
       for (int j = 0; j < k[i].size(); j++) {
            res += img[r + i][c + j] * k[k.size() - i - 1][k[i].size() - j - 1];
       }
   }
   return res;
}

vector<vector<int>> solve(vector<vector<int>> &img, vector<vector<int>> &k) {
    auto res = vector<vector<int>>(img.size() - k.size() + 1);
    auto c = img[0].size() - k[0].size() + 1;
    for (int i = 0; i < res.size(); i++) {
        res[i] = vector<int>(c);
        for (int j = 0; j < c; j++) {
            res[i][j] = solve(img, k, i, j); 
        }
    }
    return res;
}

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<int>> img(h), k(n);
    for (auto &r : img) {
        r = vector<int>(w);
        for (auto &e : r) {
            cin >> e;
        }
    }
    for (auto &r : k) {
        r = vector<int>(m);
        for (auto &e : r) {
            cin >> e;
        }
    }
    auto res = solve(img, k);
    for (auto &r : res) {
        for (auto e : r) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
