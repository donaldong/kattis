/**
 *  @brief   Kattis - Kletva 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/21/2017
 *  
 *  + Implementation
 *  + Hash
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

class Key {
public:
    vector<int> up, down;
    int h;

    Key() {}

    Key(vector<int> &up, vector<int> &down) {
        this->up = up;
        this->down = down;
        h = up[0] + down[0];
    }
    
    Key rotate() {
        vector<int> a = down, b = up;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return Key(a, b);
    }

    string toString(vector<int> &v) {
        string res = "";
        for (int i = 1; i < v.size(); i++) res += to_string(v[i]) + ",";
        return res;
    }

    vector<int> diff(vector<int> &v) {
        vector<int> res(v.size());
        for (int i = v.size() - 1; i > 0; --i) {
            res[i] = v[i] - v[i - 1];
        }
        return res;
    }

    string toString() {
        auto a = diff(up);
        auto b = diff(down);
        return to_string(h) + "|" + toString(a) + "|" + toString(b);
    }
};

int main() {
    int W, L, N;
    cin >> W >> L >> N;
    hset<string> keys;
    while (N--) {
        vector<int> up(L), down(L);
        for (int &e : up) cin >> e;
        for (int &e : down) cin >> e;
        Key k(up, down);
        string ks = k.toString();
        string rks = k.rotate().toString();
        if (ks != rks) {
            keys.insert(ks);
            keys.insert(rks);
        } else {
            keys.insert(ks);
            keys.insert(rks + "R");
        }
    }
    cout << keys.size()/2 << endl;
    return 0;
}
