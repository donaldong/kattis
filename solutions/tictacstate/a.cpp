/**
 * @date        2022-04-06
 * @tags        implementation, bit mask
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int TC;
  cin >> TC;
  for (int tc = 0; tc < TC; ++tc) {
    string num;
    cin >> num;
    while (num.size() < 8) num = '0'+num;
    vector<bool> played(9, false);
    auto xbits = played;
    int moves = 0;
    for (int r = 0; r < 3; ++r) {
      int bit = num[num.size()-r-1]-'0';
      for (int c = 0; c < 3; ++c) if (bit & (1<<c)) played[r*3+c] = true, ++moves;
    }
    for (int r = 0; r < 3; ++r) {
      int bit = num[num.size()-r-4]-'0';
      for (int c = 0; c < 3; ++c) if (bit & (1<<c)) xbits[r*3+c] = true;
    }
    bool oturn = num[1] == '1';

    const static vector<tuple<int,int,int>> pos{
      {0,1,2},
      {3,4,5},
      {6,7,8},
      {0,3,6},{1,4,7},{2,5,8},
      {0,4,8},{2,4,6},
    };

    int winner = -1;
    for (auto [a,b,c] : pos) {
      if (!played[a] || !played[b] || !played[c]) continue;
      if (xbits[a] == xbits[b] && xbits[b] == xbits[c]) {
        winner = xbits[a];
        break;
      }
    }

    if (winner >= 0) printf("%s wins\n", winner == 0 ? "O" : "X");
    else printf("%s\n", moves == 9 ? "Cat's" : "In progress");
  }
  return 0;
}
