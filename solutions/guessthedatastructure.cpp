/**
 *  @brief   Kattis - I Can Guess the Data Structure! 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/08/2018
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

string check(vector<bool> &v) {
    int count = 0;
    for (auto b : v) {
        if (b) ++count;
    }
    if (count == 0) return "impossible";
    if (count > 1) return "not sure";
    if (v[0]) return "stack";
    if (v[1]) return "queue";
    return "priority queue";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N) {
        stack<int> s;
        queue<int> q;
        pq<int, vector<int>, less<int>> q2;
        vector<bool> v(3, true);
        while (N--) {
            int op, e;
            cin >> op >> e;
            if (op == 1) {
                s.push(e);
                q.push(e);
                q2.push(e);
            } else {
                if (s.empty()) v[0] = false;
                else {
                    if (s.top() != e) v[0] = false;
                    s.pop();
                }
                if (q.empty()) v[1] = false;
                else {
                    if (q.front() != e) v[1] = false;
                    q.pop();
                }
                if (q2.empty()) v[2] = false;
                else {
                    if (q2.top() != e) v[2] = false;
                    q2.pop();
                }
            }
        }
        cout << check(v) << endl;
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
