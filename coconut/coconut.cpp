#include <bits/stdc++.h>
using namespace std;

using ti = tuple<int, int>;
using vti = vector<ti>;

int FOLD = 0, FIST = 1, PALM = 2;

bool end(vti &P) {
  if (P.size() > 2) return false;
  if (P.size() == 1) return true;
  return get<0>(P[0]) == get<0>(P[1]);
}

int step(vti &P, int s, int k) {
  int i = k - 1, j = get<0>(P[k]), h;
  while (s) {
    i = (i + 1) % P.size();
    --s;
  }
  tie(j, h) = P[i];
  if (h == FOLD) {
    auto t = make_tuple(j, FIST);
    P[i] = t;
    P.insert(P.begin() + i, t);
    return i;
  } else if (h == FIST) {
    P[i] = make_tuple(j, PALM);
    return (i + 1) % P.size();
  }
  P.erase(P.begin() + i);
  return i % P.size();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int s, n, k = 0;
  cin >> s >> n;

  vti players;
  players.reserve(n);
  for (int i = 0; i < n; ++i) players.emplace_back(i, FOLD);
  do {
    k = step(players, s, k);
#ifdef DEBUG
    for (size_t i = 0; i < players.size(); ++i) {
      int j, h;
      tie(j, h) = players[i];
      printf("(%d %d) ", j + 1, h);
    }
    printf("\n");
#endif
  } while (!end(players));
  printf("%d\n", get<0>(players[0]) + 1);
  return 0;
}
