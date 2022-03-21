#include <bits/stdc++.h>
using namespace std;
int N, P, K, C;
vector<int> D, G, vis;
vector<long long> presum;
int cycleStart = -1, cycleEnd = -1;

void dfs(int i) {
  vis[i] = 1;
  int j = G[i];
  if (vis[j] == 0) dfs(j);
  else if (vis[j] == 1) {
    cycleEnd = i;
    cycleStart = j;
    return;
  }
  vis[i] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> P >> K;
  G.resize(N), D.resize(N), presum.resize(N);
  vis.assign(N, 0);
  for (int& d : D) cin >> d;
  presum[0] = D[0];
  for (int i = 1; i < N; ++i) presum[i]=presum[i-1]+D[i];

  C = P/presum.back();
  int r = P%presum.back();
  if (!r) {
    cout << (long long)C*K << endl;
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    long long rightDuration = presum.back();
    if (i) rightDuration -= presum[i-1];
    if (rightDuration >= r) {
      auto limit = (i?presum[i-1]:0)+r;
      auto itr = upper_bound(presum.begin(), presum.end(), limit);
      G[i] = distance(presum.begin(), itr)%N;
    } else {
      auto limit = r-rightDuration;
      auto itr = upper_bound(presum.begin(), presum.end(), limit);
      G[i] = distance(presum.begin(), itr)%N;
    }
  }

  int i = 0, cycleLen = 0, inCycle = 0;
  dfs(i);
  long long res = 0, cycleRes = 0;
  while (K) {
    --K;
    int j = G[i], cnt = C;
    if (j < i) ++cnt;

    if (i == cycleStart) inCycle = 1;
    if (inCycle) ++cycleLen, cycleRes += cnt;
    else res += cnt;

    if (i == cycleEnd) {
      int rep = 1+K/cycleLen;
      res += cycleRes * rep;
      K %= cycleLen;
      cycleRes = 0;
    }
    i = j;
  }
  cout << res+cycleRes << endl;
  return 0;
}
