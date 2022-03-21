/**
 *  @brief   Kattis - Haiku 
 *  @author  Donald Dong (@donaldong)
 *  @date    02/13/2018
 *  
 *  + Brute Force
 *  + Memoization
 *  + DFS
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define hset unordered_set
#define hmap unordered_map

hmap<string, hset<int>> M;

hset<int> solve(string &t, hset<string> &S) {
    if (M.find(t) != M.end()) return M[t];
    hset<int> res;
    for (auto &s : S) {
        if (s == t) res.insert(1);
        else if (t.find(s) == 0) {
            auto t2 = t.substr(s.size(), t.size() - s.size());
            auto N = solve(t2, S);
            for (int n : N) res.insert(n + 1);
        }
    }
    M[t] = res;
    return res;
}

bool solve(vector<vector<int>> &t, int sum, int i, int n) {
    if (i >= t.size()) return false;
    for (int j = 0; j < t[i].size(); ++j) {
        int nsum = sum + t[i][j];
        if (nsum == n) return i + 1 == t.size();
        if (nsum > n) return false;
        if (solve(t, nsum, i + 1, n)) return true;
    }
    return false;
}

bool possible(vector<string> &v, int n, hset<string> &S) {
    vector<vector<int>> t(v.size());
    if (t.size() > n) return false;
    int sum = 0;
    for (int i = 0; i < t.size(); ++i) {
        auto s = solve(v[i], S);
        if (s.empty()) continue;
        t[i] = vector<int>(s.size());
        int k = 0;
        for (int j : s) t[i][k++] = j; 
        sort(t[i].begin(), t[i].end());
        if (t[i][0] > n) return false;
        sum += t[i][0];
    }
    if (sum > n) return false;
    return solve(t, 0, 0, n);
}

bool possible(string &line, int n, hset<string> &S) {
    stringstream ss(line);
    vector<string> v;
    string token;
    while (ss >> token) {
        v.push_back(token);
    }
    return possible(v, n, S);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s;
    cin >> s;
    hset<string> S;
    while (s--) {
        string n;
        cin >> n;
        S.insert(n);
    }
    cin.ignore();
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    cout << (possible(a, 5, S) && possible(b, 7, S) && possible(c, 5, S) ? "haiku" : "come back next year") << endl;
    return 0;
}
