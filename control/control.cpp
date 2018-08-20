#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map

// max number of ingredients
int MAX_M = 500001;
vector<int> M(MAX_M, -1);
// potions <idx, <ingredients>>
hmap<int, vector<int>> P;

bool possible(vector<int> &I, int i) {
  vector<int> A, B;
  for (int e : I) {
    if (M[e] != -1) {
      A.push_back(e);
      for (int b : P[M[e]]) {
        B.push_back(b);
      }
    }
  } 
  sort(B.begin(), B.end());
  auto end = unique(B.begin(), B.end());
  int j = 0;
  B.resize(distance(B.begin(), end));
  if (A.size() != B.size()) return false;
  for (int b : B) {
    if (b != A[j++]) return false;
  }
  for (int a : A) {
    P[a].clear();
  }
  for (int e: I) {
    if (M[e] == -1) B.push_back(e);
    M[e] = i;
  }
  P[i] = B;
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
    vector<int> I(k);
    for (auto &e : I) cin >> e;
    if (possible(I, i)) ++res;
  }
  cout << res << endl;
  return 0;
}
