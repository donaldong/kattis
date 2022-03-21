#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> A(n);
  for (int& a : A) cin >> a;
  unordered_set<int> s(A.begin(), A.end());
  switch (t) {
  case 1: {
    bool found = false;
    for (int v : s) {
      if (s.count(7777-v)) {
        found = true;
        break;
      }
    }
    cout << (found?"Yes":"No") << endl;
    break;
  }
  case 2: {
    cout << (s.size()==A.size()?"Unique":"Contains duplicate")<<endl;
    break;
  }
  case 3: {
    unordered_map<int,int> freq;
    for (int a : A) ++freq[a];
    bool found = false;
    for (auto [a, f] : freq) {
      if (f*2>A.size()) {
        cout << a << ' ';
        found = true;
      }
    }
    if (found) cout << endl;
    else cout << -1 << endl;
    break;
  }
  case 4: {
    sort(A.begin(), A.end());
    if (A.size()&1) {
      cout << A[A.size()/2] << endl;
    } else {
      cout << A[A.size()/2-1] << ' ' << A[A.size()/2] << endl;
    }
    break;
  }
  case 5: {
    sort(A.begin(), A.end());
    for (int a : A) {
      if (a >= 100 && a <= 999) cout << a << ' ';
    }
    cout << endl;
    break;
  }
  }
  return 0;
}
