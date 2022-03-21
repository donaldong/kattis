/**
 *  @brief   Kattis - Rhyming Slang 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/26/2017
 *  
 *  + Implementation
 *  + Bad Description
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

hset<string> get_ending(vector<hset<string>> &V, string &s) {
    hset<string> res;
    for (auto &v : V) {
        for (auto n : v) {
            if (n.size() > s.size()) continue;
            string sub = s.substr(s.size() - n.size(), n.size());
            if (sub == n) res.insert(n);
        }
    }
    return res;
}

bool possible(vector<hset<string>> &V, string &s, hset<string> &endings) {
    for (auto n : endings) {
        for (auto v : V) {
            if (v.find(n) == v.end()) continue;
            for (auto n : v) {
                if (n.size() > s.size()) continue;
                string sub = s.substr(s.size() - n.size(), n.size());
                if (sub == n) return true;
            }
        }
    }
    return false;
}

int main() {
    string S;
    cin >> S;
    int E;
    cin >> E;
    vector<hset<string>> V;
    cin.ignore();
    while (E--) {
        hset<string> v;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string s;
        while (getline(ss, s, ' ')) {
            if (s.empty()) continue;
            v.insert(s);
        }
        V.push_back(v);
    }
    auto endings = get_ending(V, S);
    int P;
    cin >> P;
    cin.ignore();
    while (P--) {
        string line;
        getline(cin, line);
        vector<string> v;
        stringstream ss(line);
        string s;
        while (getline(ss, s, ' ')) {
            if (s.empty()) continue;
            v.push_back(s);
        }
        cout << (possible(V, v.back(), endings) ? "YES" : "NO") << endl;
    }
    return 0;
}
