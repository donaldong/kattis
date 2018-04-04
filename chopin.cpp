#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<string, string> t, m;
    t["A#"] = "Bb";
    t["C#"] = "Db";
    t["D#"] = "Eb";
    t["F#"] = "Gb";
    t["G#"] = "Ab";
    for (auto e : t) {
        m[e.second] = e.first;
    }
    string a, b;
    int i = 1;
    while (cin >> a) {
        cin >> b;
        cout << "Case " << i++ << ": ";
        if (m.find(a) == m.end()) {
            cout << "UNIQUE" << endl;
        } else {
            cout << m[a] << " " << b << endl;
        }
    }
    return 0;
}

