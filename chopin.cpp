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
    unordered_map<string, string> m;
    m["A#"] = "Bb";
    m["C#"] = "Db";
    m["D#"] = "Eb";
    m["F#"] = "Gb";
    m["G#"] = "Ab";

    m["Bb"] = "A#";
    m["Db"] = "C#";
    m["Eb"] = "D#";
    m["Gb"] = "F#";
    m["Ab"] = "G#";
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


