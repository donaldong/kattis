#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct expr {
    int a, b;
};

ll calc(int a, int b, char op) {
    if (op == 0) return a + b;
    if (op == 1) return a - b;
    ll res = a;
    return res * b;
}

vector<int> match;

bool bpm(vector<vector<bool>> &G, int n, vector<bool> &seen) {
    for (int m = 0; m < G[n].size(); ++m) {
        if (G[n][m] && !seen[m]) {
            seen[m] = true;
            if (match[m] < 0 || bpm(G, match[m], seen)) {
                match[m] = n;
                return true;
            }
        }
    }
    return false;
}

bool possible(vector<vector<bool>> &G) {
    match = vector<int>(G[0].size(), -1);
    for (int i = 0; i < G.size(); ++i) {
        vector<bool> seen(G[i].size(), false);
        if (!bpm(G, i, seen)) return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    vector<expr> E(n);
    vector<ll> A(3 * n);
    for (int i = 0; i < n; ++i) {
        cin >> E[i].a >> E[i].b;
        for (int j = 0; j < 3; ++j) {
            A[3 * i + j] = calc(E[i].a, E[i].b, j);
        }
    }
    bool f = true;
    sort(A.begin(), A.end());
    auto end = unique(A.begin(), A.end());
    if (distance(A.begin(), end) + 1 < E.size()) f = false;
    else {
        vector<vector<bool>> G(n, vector<bool>(A.size(), false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                ll val = calc(E[i].a, E[i].b, j);
                auto itr = lower_bound(A.begin(), end, val);
                int k = distance(A.begin(), itr); 
                G[i][k] = true;
            }
        }
        f = possible(G);
    }
    if (!f) cout << "impossible" << endl;
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                ll val = calc(E[i].a, E[i].b, j);
                auto itr = lower_bound(A.begin(), end, val);
                int k = distance(A.begin(), itr);
                if (match[k] == i) {
                    cout << E[i].a << " ";
                    if (j == 0) cout << "+ ";
                    else if (j == 1) cout << "- ";
                    else cout << "* ";
                    cout << E[i].b << " = " << val << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
