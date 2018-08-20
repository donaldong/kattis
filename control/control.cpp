#include <bits/stdc++.h>
using namespace std;

#define hmap unordered_map
#define hset unordered_set

// max number of ingredients
int MAX_M = 500001;
vector<int> M(MAX_M, -1);

bool possible(vector<int> &I, int r) {
  sort(I.begin(), I.end());
  int k = 0;
  hset<int> A;
  for (int i : I) {
    if (M[i] == -1) continue;
    A.insert(M[i]);
  }
  for (int i = 0; i < MAX_M; ++i) {
    if (M[i] == -1) continue;
    if (k < I.size() && i == I[k]) {
      ++k;
      continue;
    }
    if (A.find(M[i]) != A.end()) return false;
  }
  for (int i : I) {
    M[i] = r;
  }
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
