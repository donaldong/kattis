#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, c, id = 0;
  cin >> n >> c;
  vector<int> N(n);
  unordered_map<int,int> freq, ID;
  for (int& v : N) {
    cin >> v;
    ++freq[v];
    if (!ID.count(v)) ID[v] = id++;
  }
  sort(N.begin(), N.end(), [&](int a, int b) {
    if (freq[a]!=freq[b]) return freq[a]>freq[b];
    return ID[a]<ID[b];
  });
  for (int v : N) cout << v << ' ';
  cout << endl;
  return 0;
}
