/**
 * @date        2022-04-06
 * @tags        data structure
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXL=11;
constexpr int MAXN=100000*MAXL;

template <class T>
struct Eq : binary_function<T,T,bool> {
  bool operator()(const T& a, const T& b) const {
    return strcmp(a, b) == 0;
  }
};

struct HashChars {
  int operator()(char* str) const {
    const int p = 131;
    int hash = 0;
    for (; *str; ++str) hash = hash*p+*str;
    return hash & (0x7FFFFFFF);
  }
};

// An attempt to make the program run as fast as possible
// by using one single pre-allocated buffer
using Dict = unordered_map<char*,char*, HashChars, Eq<char*>>;
char buff[3*MAXN];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  Dict dict;
  int i, len;
  char c, *a, *b;
  for (i = 0;; ++i) {
    len = 0, a = &buff[i];
    for (;; ++i) {
      c = getchar();
      if (c == ' ') {
        b = &buff[i+1];
        c = 0;
      } else if (c == '\n') break;
      buff[i] = c, ++len;
    }
    buff[i] = 0;
    if (len == 0) break;
    dict[b] = a;
  }
  for (;; ++i) {
    a = &buff[i];
    for (;; ++i) {
      c = getchar();
      if (c == EOF) return 0;
      if (c == '\n') c = 0;
      buff[i] = c;
      if (!c) break;
    }
    auto itr = dict.find(a);
    printf("%s\n", itr==dict.end() ? "eh" : itr->second);
  }
  return 0;
}
