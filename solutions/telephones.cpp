/**
 *  @brief   Kattis - Happy Telephones
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2018
 *  
 *  + Funny
 *  + Brute Force
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

struct call {
    int start, duration;
    call() {}
    call(int start, int duration) : start(start), duration(duration) {}
};

bool in(call &c, int start, int duration) {
    int a = max(c.start, start);
    int b = min(c.start + c.duration, start + duration);
    return b > a;
}

void scan(int &number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    while (true) {
        scan(N); scan(M);
        if (!N && !M) break;
        vector<call> C(N);
        for (vector<call>::iterator c = C.begin(); c != C.end(); ++c) {
            int a, b;
            scan(a); scan(b); scan(c->start); scan(c->duration);
        }
        while (M--) {
            int res = 0;
            int start, duration;
            scan(start); scan(duration);
            for (vector<call>::iterator c = C.begin(); c != C.end(); ++c) {
                if (in(*c, start, duration)) ++res;               
            }
            cout << res << endl;
        }
    }
    return 0;
}
