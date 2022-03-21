#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  char v;
  cin >> n;
  vector<bool> V(n);
  for (int i = 0; i < n; ++i) {
    cin >> v;
    V[i] = v == 'T';
  }
  vector<bool> s;
  while (cin >> v) {
    switch (v) {
      case '-': {
        s.back() = !s.back();
        break;
      }
      case '+': {
        bool b = s.back();
        s.pop_back();
        bool a = s.back();
        if (a) s.back() = true;
        else {
          s.back() = b;
        }
        break;
      }
      case '*': {
        bool b = s.back();
        s.pop_back();
        bool a = s.back();
        if (a && b) s.back() = true;
        else s.back() = false;
        break;
      }
      default: {
        s.push_back(V[v-'A']);
        break;
      }
    }
  }
  cout << (s.back() ? 'T' : 'F') << endl;
  return 0;
}
