/**
 *  @brief   Kattis - Dacey the Dice 
 *  @author  Donald Dong (@donaldong)
 *  @date    03/08/2018
 *  
 *  + Graph
 *  + BFS
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

int DR[] = {-1, 1, 0, 0};
int DC[] = {0, 0, -1, 1};

class Dice {
    int bottom = 0;
    int top = 1;
    int right = 2;
    int left = 3;
    int front = 4;
    int back = 5;
    vector<int> A;
public:
    Dice() {
        A = {6, 1, 2, 5, 4, 3};
    }

    void move(int dir) {
        vector<int> B(6);
        if (dir == 0) {
            B[left] = A[left];
            B[right] = A[right];
            B[front] = A[top];
            B[top] = A[back];
            B[back] = A[bottom];
            B[bottom] = A[front];
        } else if (dir == 1) {
            B[left] = A[left];
            B[right] = A[right];
            B[front] = A[bottom];
            B[top] = A[front];
            B[back] = A[top];
            B[bottom] = A[back];
        } else if (dir == 2) {
            B[front] = A[front];
            B[back] = A[back];
            B[left] = A[top];
            B[top] = A[right];
            B[right] = A[bottom];
            B[bottom] = A[left];
        } else {
            B[front] = A[front];
            B[back] = A[back];
            B[left] = A[bottom];
            B[top] = A[left];
            B[right] = A[top];
            B[bottom] = A[right];
        }
        A = B;
    }

    int key() {
        int res = 0;
        for (int i = 5; i >= 0; --i) {
            res = res * 6 + A[i] - 1;
        }
        return res;
    }
};

struct point {
    int r, c;
    Dice dice;
    point() {}
    point(int r, int c) : r(r), c(c) 
    { }
};

bool possible(vector<string> &G, point &src, point &home) {
    vector<vector<hset<int>>> M(G.size(), vector<hset<int>>(G.size()));
    queue<point> Q;
    Q.push(src);
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int r = cur.r + DR[i];
            int c = cur.c + DC[i];
            if (r >= 0 && r < G.size() && c >= 0 && c < G.size()) {
                if (G[r][c] == '*') continue;
                Dice dice = cur.dice;        
                dice.move(i);
                int key = dice.key();
                if (M[r][c].find(key) == M[r][c].end()) {
                    M[r][c].insert(key);
                    point np(r, c);
                    np.dice = dice;
                    Q.push(np);
                }
            }
        }
    }
    for (int k : M[home.r][home.c]) {
        if (k % 6 == 4) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> G(N);
        point src, home;
        for (int i = 0; i < N; ++i) {
            cin >> G[i];
            for (int j = 0; j < N; ++j) {
                if (G[i][j] == 'S') src = point(i, j);
                if (G[i][j] == 'H') home = point(i, j);
            }
        }
        cout << (possible(G, src, home) ? "Yes" : "No") << endl;
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
