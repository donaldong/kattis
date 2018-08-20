#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map
#define hset unordered_set

// max number of ingredients
int MAX_M = 500001;
vector<int> M(MAX_M, -1);
// potions <idx, <ingredients>>
hmap<int, hset<int>> P;

bool possible(hset<int> &I, int i) {
  for (int e : I) {
    if (M[e] != -1) {
      for (int b : P[M[e]]) {
        if (I.find(b) == I.end()) return false;
      }
    }
  } 
  for (int e : I) {
    if (M[e] != -1) P[M[e]].clear();
    M[e] = i;
  }
  P[i] = I;
  return true;
}

int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    // ingredients
    hset<int> I;
    for (int j = 0; j < k; ++j) {
      int p;
      cin >> p;
      I.insert(p);
    }
    if (possible(I, i)) ++res;
  }
  cout << res << endl;
  return 0;
}
