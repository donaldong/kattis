/**
 *  @brief   Kattis - Where's My Internet?? 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/16/2017
 *  
 *  + Graph
 *  + Disjoint Set
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

struct node {
    int r = 0;
    node *p = 0;
};

node* find(node* n) {
    if (n->p != n)
        n->p = find(n->p);
    return n->p;
}

void u(node *a, node *b) {
    if (a->r > b->r) {
        b->p = a;
    } else if (a->r < b->r) {
        a->p = b;
    } else {
        b->p = a;
        a->r++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<node> nodes(n);
    for (auto &node : nodes) {
        node.p = &node;
    }
    auto root = &nodes[0];
    root->r = INT_MAX;
    while (m--) {
        int x, y;
        cin >> x >> y;
        auto a = &nodes[x-1];
        auto b = &nodes[y-1];
        auto pa = find(a);
        auto pb = find(b);
        if (pa != pb) u(pa, pb);
    }
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (find(&nodes[i]) != root) {
            cout << i + 1 << endl;
            connected = false;
        }
    }
    if (connected) cout << "Connected" << endl;
    return 0;
}
