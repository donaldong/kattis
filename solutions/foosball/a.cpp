/**
 * @date        2022-10-31
 * @tags        implementation
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  deque<int> Q, W, B;
  int n;
  cin >> n;
  vector<string> players(n);
  for (auto& p : players) cin >> p;
  W.push_back(0), W.push_back(2);
  B.push_back(1), B.push_back(3);
  string s;
  cin >> s;
  for (int i = 4; i < n; ++i) Q.push_back(i);

  auto updateOnWin = [&](deque<int>& team) {
    swap(team[0], team[1]);
  };
  auto updateOnLose = [&](deque<int>& team) {
    Q.push_back(team.back());
    team.pop_back();
    team.push_front(Q.front());
    Q.pop_front();
  };

  vector<tuple<char/*team*/,int/*player1*/,int/*player2*/,int/*score*/>> scores{{' ', 0, 0, 0}};
  vector<int> turn(n, -1);
  int max_score = 1;
  for (int i = 0; i < s.size(); ++i) {
    deque<int> *w = &W, *l = &B;
    if (s[i] == 'B') swap(w, l);
    turn[Q.front()] = i;
    if (s[i] == get<0>(scores.back())) {
      auto& score = get<3>(scores.back());
      ++score;
      max_score = max(max_score, score);
    } else {
      int a = w->at(0), b = w->at(1);
      if (turn[a] > turn[b]) swap(a, b);
      scores.emplace_back(s[i], a, b, 1);
    }
    updateOnWin(*w), updateOnLose(*l);
  }
  for (auto [t, a, b, score] : scores) {
    if (score == max_score) cout << players[a] << ' ' << players[b] << '\n';
  }
  return 0;
}
