/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Segment Tree
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

const ull MOD = 1e9 + 7;
const int ALPHABET_SIZE = 26;

struct node {
    int sum = 0;
    int start, end, i;
    string val;
    node *left, *right, *parent = 0;
    node(int start = 0, int end = 0) {
        this->start = start;
        this->end = end;
    }
    int query(int start, int end) {
        if (this->start >= start && this->end <= end) return sum;
        if (this->start > end || this->end < start) return 0;
        int res = left->query(start, end);
        if (right) res += right->query(start, end);
        return res;
    }
    void update(int pos) {
        if (start > pos || end < pos) return;
        ++sum;
        if (parent) parent->update(pos);
    }
};

node *join(node *a, node *b) {
    if (!b) return a;
    auto res = new node();
    res->left = a;
    res->right = b;
    res->start = a->start;
    res->end = b->end;
    a->parent = res;
    b->parent = res;
    return res;
}

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode *getNode() {
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    hmap<string, node*> M;
    vector<node*> nodes(n);
    auto trie = getNode();
    rep(i, 0, n) {
        nodes[i] = new node();
        cin >> nodes[i]->val;
        insert(trie, nodes[i]->val);
        M[nodes[i]->val] = nodes[i];
    }
    sort(nodes.begin(), nodes.end(), [](node *a, node *b) {
        return a->val < b->val;
    });
    rep(i, 0, n) {
        nodes[i]->i = i;
        nodes[i]->start = i;
        nodes[i]->end = i;
    }
    while (nodes.size() > 1) {
        int size = nodes.size() / 2;
        if (nodes.size() & 1) ++size;
        vector<node*> new_nodes(size);
        for (int i = 0; i < nodes.size(); i += 2) {
            node *next_node = 0;
            if (i + 1 < nodes.size()) next_node = nodes[i + 1];
            new_nodes[i / 2] = join(nodes[i], next_node);
        }
        nodes = new_nodes;
    }
    node *root = nodes[0];
    string target;
    cin >> target;
    ull res = 1;
    vector<ull> P(k);
    P[0] = 1;
    rep(i, 1, k) {
        res *= n - k + i;
        res %= MOD;
        P[i] = res;
    }
    res = 0;
    int i = 0, j = 1;
    string prefix;
    auto p = trie;
    while (i < target.size()) {
        int index = target[i] - 'a';
        prefix += target[i++];
        p = p->children[index];
        if (!p->isEndOfWord) continue;
        p = trie;
        auto cur = M[prefix];
        int d = cur->i - root->query(0,  cur->i);
        cur->update(cur->i);
        if (d <= 0) {
            ++j;
            prefix = "";
            continue;
        }
        ull r = d * P[P.size() - j];
        r %= MOD;
        res += r;
        res %= MOD;
        ++j;
        prefix = "";
    }
    ++res;
    res %= MOD;
    cout << res << endl;
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
