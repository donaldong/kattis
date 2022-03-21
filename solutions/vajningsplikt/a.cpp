#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> D{
  {"North", 0},
  {"East", 1},
  {"South", 2},
  {"West", 3},
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> V(3);
  string s;
  for (auto& v : V) {
    cin >> s;
    v = D[s];
  }
  int d = 2-V[0];
  for (auto& v : V) {
    v = (v+d+4)%4;
  }
  bool shouldYield = false;
  switch (V[1]) {
  case 0:
    shouldYield = V[2] == 1;
    break;
  case 3:
    shouldYield = V[2] == 0 || V[2] == 1;
    break;
  }
  cout << (shouldYield ? "Yes" : "No") << endl;
  return 0;
}
