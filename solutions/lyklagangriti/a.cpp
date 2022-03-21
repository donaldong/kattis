#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string line;
  cin >> line;
  list<char> L;
  auto itr = L.begin();
  for (char c : line) {
    switch (c) {
    case 'B': {
      --itr;
      itr = L.erase(itr);
      break;
    }

    case 'L': {
      --itr;
      break;
    }

    case 'R': {
      ++itr;
      break;
    }

    default: {
      L.insert(itr, c);
      break;
    }
    }
  }
  for (char c : L) cout << c;
  cout << endl;
  return 0;
}
