/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + TAG
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

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

vector<double> gauss(vector<vector<double>> &A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }
        for (int k=i; k<n+1;k++) swap(A[maxRow][k], A[i][k]);
        for (int k=i+1; k<n; k++) {
            double c = 1;
            if (A[i][i] != 0) c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
        print(A);
    }
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = 1;
        if (A[i][i] != 0) x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    for (auto &e : x) cout << e << " ";
    cout << endl;
    return x;
}

bool valid(vector<vector<double>> &G, vector<double> &x) {
    rep(i, 0, 3) {
        bool f = true;
        rep(j, 0, 3) {
            if (G[i][j] > 0) {
                if (!f) return false;
                if (j != i) return false;
                f = false;
            }
        }
        if (f && G[i][3] >= 0) return false;
    }
    for (auto &e : x) if (e < 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        vector<vector<double>> mat(3, vector<double>(4));
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
        mat[0][0] = a;
        mat[1][0] = b;
        mat[2][0] = c;
        rep(i, 1, 3) {
            rep(j, 0, 3) {
                cin >> mat[j][i];
            }
        }
        cin >> mat[0][3] >> mat[1][3] >> mat[2][3];
        auto x = gauss(mat);
        cout << (valid(mat, x) ? "YES" : "NO") << endl;
    }
    return 0;
}

inline void scan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void scan(ll &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void print(uint n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[11];
    int i = 10;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 10) putchar(buf[++i]);
}

inline void print(ull n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[20];
    int i = 19;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 19) putchar(buf[++i]);
}

inline void print(string &s) {
    rep(i, 0, s.length()) putchar(s[i]);
}
