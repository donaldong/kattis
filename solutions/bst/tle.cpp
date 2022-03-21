#include <bits/stdc++.h>
using namespace std;
int root = -1;
vector<int> L, R;

int insert(int p, int n, int d) {
#ifdef DEBUG
  printf("insert(%d,%d,%d)\n", p, n, d);
#endif
  if (n < p) {
    if (L[p] < 0) {
      L[p] = n;
      return d+1;
    }
    return insert(L[p], n, d+1);
  }
  if (R[p] < 0) {
    R[p] = n;
    return d+1;
  }
  return insert(R[p], n, d+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  L.assign(n, -1);
  R.assign(n, -1);
  long long C = 0;
  while (n--) {
    int v;
    cin >> v;;
    --v;
    if (root < 0) {
      root = v;
    } else {
      int d = insert(root, v, 0);
      C += d;
    }
    cout << C << endl;
  }
  return 0;
}
