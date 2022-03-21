/**
 *  @brief   Kattis - Music Your Way 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/20/2018
 *  
 *  + Implementation
 *  + Recursion
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

typedef vector<string> song;

void merge(vector<song> &A, int k, int beg, int mid, int end) {
    int l = mid - beg + 1, r = end - mid;
    vector<song> L(l), R(r);
    for (int i = 0; i < l; ++i) L[i] = A[beg + i];
    for (int i = 0; i < r; ++i) R[i] = A[mid + i + 1];
    l = r = 0;
    for (int i = beg; i <= end; ++i) {
        if (l == L.size()) A[i] = R[r++];
        else if (r == R.size()) A[i] = L[l++];
        else if (L[l][k] <= R[r][k]) A[i] = L[l++];
        else A[i] = R[r++];
    }
}

void merge_sort(vector<song> &songs, int k, int beg, int end) {
    if (beg >= end) return;
    int mid = (beg + end) / 2;
    merge_sort(songs, k, beg, mid);
    merge_sort(songs, k, mid + 1, end);
    merge(songs, k, beg, mid, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    hmap<string, int> M;
    vector<string> A;
    for (int i = 0; ss >> token; ++i) {
         M[token] = i;
         A.pb(token);
    }
    int m, n;
    cin >> m;
    vector<song> songs(m);
    for (auto &s : songs) {
        rep(i, 0, M.size()) {
            cin >> token;
            s.pb(token);
        }
    }
    cin >> n;
    rep(j, 0, n) {
        cin >> token;
        merge_sort(songs, M[token], 0, m - 1);
        for (string &a : A) cout << a << " ";
        cout << endl;
        for (auto &s : songs) {
            for (int i = 0; i < s.size(); ++i) {
                cout << s[i] << " ";
            }
            cout << endl;
        }
        cout << endl;
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
