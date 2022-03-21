#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<long long> A(n);
  for (long long& a : A) cin >> a;
  if (t == 1) {
    cout << 7 << endl;
  } else if (t == 2) {
    if (A[0] > A[1]) cout << "Bigger" << endl;
    else if (A[0] == A[1]) cout << "Equal" << endl;
    else cout << "Smaller" << endl;
  } else if (t == 3) {
    vector<long long> v{A[0], A[1], A[2]};
    sort(v.begin(), v.end());
    cout << v[1] << endl;
  } else if (t == 4) {
    long long res = 0;
    for (long long a : A) res += a;
    cout << res << endl;
  } else if (t == 5) {
    unsigned long long res = 0;
    for (long long a : A) if (a%2==0) res += a;
    cout << res << endl;
  } else if (t == 6) {
    for (long long a : A) cout << a%26+'a'
    cout << res << endl;
  } else { // t==7
    long long i = A[0];
    unordered_set<long long> vis;
    vis.insert(0);
    while (true) {
      i = A[i];
      if (i >= n) {
        cout << "Out" << endl;
        break;
      }

      if (i+1==n) {
        cout << "Done" << endl;
        break;
      }

      if (vis.count(i)) {
        cout << "Cyclic" << endl;
        break;
      }

      vis.insert(i);
    }
  }
  return 0;
}

