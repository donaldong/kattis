/**
 * @date        2022-12-16
 * @tags        linked list
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, q;
  cin >> n >> q;
  vector<string> N(2*n);
  list<int> L;
  // store the iterator for each person for type C query
  vector<decltype(L)::iterator> P(2*n);
  for (int i = 0; i < n; ++i) {
    int a = 2*i, b = 2*i+1;
    cin >> N[a] >> N[b];
    P[a] = L.insert(L.end(), a);
    P[b] = L.insert(L.end(), b);
  }
  string Q;
  cin >> Q;
  auto itr = L.begin(); // mic
  for (char c : Q) {
    switch (c) {
      case 'F': itr = prev(itr); break;
      case 'B': itr = next(itr); break;
      case 'R': {
        int p = *itr;
        itr = L.erase(itr);
        if (itr == L.end()) itr = L.begin();
        P[p] = L.insert(L.end(), p);
        break;
      }
      case 'C': {
        int p = *itr;
        int p2 = p/2*2+1-(p%2);
        itr = L.erase(itr);
        if (itr == L.end()) itr = L.begin();
        P[p] = L.insert(next(P[p2]), p);
        break;
      }
      case 'P': {
        int p = *itr;
        int p2 = p/2*2+1-(p%2);
        cout << N[p2] << '\n';
        break;
      }
    }
  }
  cout << '\n';
  for (itr = L.begin(); itr != L.end(); ++itr) {
    cout << N[*itr] << '\n';
  }
  return 0;
}
