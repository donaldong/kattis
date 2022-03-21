#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using v2i = vector<vi>;
int INF = 1e9;

#ifdef DEBUG
void debug(v2i &G) {
  for (size_t i = 0; i < G.size(); ++i) {
    for (size_t j = 0; j < G.size(); ++j) {
      cout << G[i][j] << " ";
    }
    cout << endl;
  }
}

void debug(vi &V) {
  for (int v : V) cout << v << " ";
  cout << endl;
}
#endif

bool possible(v2i &G, string &A, string &B) {
#ifdef DEBUG
  cout << endl;
  debug(G);
#endif
  for (size_t i = 0; i < A.size(); ++i) {
    if (!G[i][i] && A[i] != B[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string word;
  int n;
  cin >> word >> n;
  string sorted_word = word;
  sort(sorted_word.begin(), sorted_word.end());
  int size = word.size();
  v2i G(size, vi(size,  0));
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (abs(i - j) >= n) G[i][j] = G[j][i] = 1;
    }
  }
#ifdef DEBUG
  debug(G);
#endif
  for (int k = 0; k < size; ++k) {
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (G[i][k] && G[k][j]) G[i][j] = 1;
      }
    }
  }
  cout << (possible(G, word, sorted_word) ? "Yes" : "No") << endl;
  return 0;
}
