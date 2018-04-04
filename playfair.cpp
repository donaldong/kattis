#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define hset unordered_set
#define hmap unordered_map

char get(vector<char> &K, int r, int c) {
    int index = r * 5 + c;
    return toupper(K[index]);
}

string parse(string &word, vector<char> &K, hmap<char, pair<int, int>> &P) {
    auto p1 = P[word[0]];
    auto p2 = P[word[1]];
    if (p1.first == p2.first) {
        int c1 = p1.second + 1;
        int c2 = p2.second + 1;
        c1 %= 5;
        c2 %= 5;
        string res = "";
        res += get(K, p1.first, c1);
        res += get(K, p1.first, c2);
        return res;
    }
    if (p1.second == p2.second) {
        int r1 = p1.first + 1;
        int r2 = p2.first + 1;
        r1 %= 5;
        r2 %= 5;
        string res = "";
        res += get(K, r1, p1.second);
        res += get(K, r2, p1.second);
        return res;
    }
    string res = "";
    res += get(K, p1.first, p2.second);
    res += get(K, p2.first, p1.second);
    return res;
}

string solve(vector<char> &K, string s) {
    hmap<char, pair<int, int>> P;
    for (int i = 0; i < K.size(); ++i) {
        P[K[i]] = make_pair(i / 5, i % 5);
    }
    string res;
    for (int i = 0; i < s.size();) {
        string word = "";
        if (i + 1 == s.size()) {
            word += s[i];
            word += 'x';
            i += 2;
        } if (s[i] == s[i + 1]) {
            word += s[i];
            word += 'x';
            i += 1;
        } else {
            word += s[i];
            word += s[i + 1];
            i += 2;
        }
        string t = parse(word, K, P);
        res += t;
    }
    return res;
}

int main() {
    string line;
    getline(cin, line);
    vector<char> K;
    hset<char> S;
    for (char c : line) {
        if (c == 'q') continue;
        if (c != ' ' && S.find(c) == S.end()) {
            K.push_back(c);
            S.insert(c);
        }
    }
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        if (c == 'q') continue;
        if (S.find(c) == S.end() && K.size() < 25) {
            S.insert(c);
            K.push_back(c);
        }
    }
    getline(cin, line);
    string s;
    for (char c : line) {
        if (c != ' ') s += c;
    }
    cout << solve(K, s) << endl;
    return 0;
}
