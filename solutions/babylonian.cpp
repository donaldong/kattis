/**
 *  @brief   Kattis - Babylonian Numbers 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/16/2017
 *  
 *  + Base Conversion
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

ull dec(vector<int> &nums, int base) {
    ull res = 0;
    for (auto n : nums) {
        res = res * base + n;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
       string str;
       cin >> str;
       vector<int> nums;
       int i = str.find(',');
       while (i >= 0) {
            if (i == 0) nums.push_back(0);
            else nums.push_back(stoi(str.substr(0, i)));
            str.erase(0, i+1);
            i = str.find(',');
       }
       if (str.size()) nums.push_back(stoi(str));
       else nums.push_back(0);
       cout << dec(nums, 60) << endl;
    }
    return 0;
}
