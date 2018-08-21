#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, set<int>> H; 
  for (int i = 0; i < N; ++i) {
    int h; 
    cin >> h;
    H[h].insert(i);
  }
  int res = 0;
  while (N) {
    auto itr = --H.end();
    int i = *itr->second.begin();
    itr->second.erase(itr->second.begin());
    --N;
    ++res;
    auto itr2 = H.find(itr->first - 1);
    if (itr->second.empty()) H.erase(itr);
    while (itr2 != H.end()) {
      auto itr3 = itr2->second.upper_bound(i);
      if (itr3 == itr2->second.end()) break;
      itr2->second.erase(itr3);
      if (itr2->second.empty()) H.erase(itr2);
      i = *itr3;
      --N;
      itr2 = H.find(itr2->first - 1);
    }
  }
  cout << res << endl;
  return 0;
}
