/**
 *  @brief   Kattis - Genealogical Research 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/31/2017
 *  
 *  + Implementation
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

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

template <class T, class U> bool in(hmap<T, U> &m, T key) { return m.find(key) != m.end(); }

struct person {
    string name;
    string birth, death;
    person *father = 0, *mother = 0;
    vector<person*> children;
    bool alive = true;
    person() {}
    person(string name) : name(name) {}
};

string parse(stringstream &ss) {
    vector<string> v;
    string s;
    while (ss >> s) v.pb(s);
    if (!v.size()) return "";
    string res;
    rep(i, 0, v.size() - 1) res += v[i] + " ";
    return res + v.back();
}

string parse(string &s) {
    stringstream ss(s);
    return parse(ss);
}

void println(string &s, int intend) {
    while (intend--) cout << "  ";
    cout << s << endl;
}

void sort(vector<person*> &s) {
    sort(s.begin(), s.end(), [](person *a, person *b) {
        return a->name < b->name;
    });
}

bool print_person(person *p, int indent) {
    string line = p->name;
    if (p->birth.size()) {
        line += " " + p->birth + " -";
        if (!p->alive) line += " " + p->death;
        println(line, indent);
        return true;
    }
    println(line, indent);
    return false;
}

void print_ancestors(person *p, int indent=1) {
    if (!p->father || !p->mother) return;
    vector<person*> parents = {p->father, p->mother};
    sort(parents);
    for (auto n : parents) {
        if (print_person(n, indent)) print_ancestors(n, indent + 1);
    }
}

void print_descendants(person *p, int indent=1) {
    sort(p->children);
    for (auto n : p->children) {
        if (print_person(n, indent)) print_descendants(n, indent + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    hmap<string, person*> P;
    bool f = false;
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        vector<string> v;
        while (getline(ss, token, ':')) {
            v.pb(token);
        }
        string cmd, name;
        ss = stringstream(v[0]);
        ss >> cmd;
        name = parse(ss);
        if (cmd == "BIRTH") {
            string date = parse(v[1]), mother = parse(v[2]), father = parse(v[3]);
            auto p = new person(name);
            p->birth = date; 
            if (!in(P, mother)) P[mother] = new person(mother);
            if (!in(P, father)) P[father] = new person(father);
            p->mother = P[mother]; p->father = P[father]; 
            p->father->children.pb(p); p->mother->children.pb(p);
            P[name] = p;
        } else if (cmd == "DEATH") {
            string date = parse(v[1]);
            P[name]->alive = false; P[name]->death = date;
        } else if (cmd == "ANCESTORS") {
            if (f) cout << endl;
            cout << "ANCESTORS of " << name << endl;
            print_ancestors(P[name]);
            f = true;
        } else if (cmd == "DESCENDANTS") {
            if (f) cout << endl;
            cout << "DESCENDANTS of " << name << endl;
            print_descendants(P[name]);
            f = true;
        } else if (cmd == "QUIT") {
            break;
        }
    }
    return 0;
}
