#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
  int n, m;
  cin >> n >> m;
  vi tasks(n), times(m);
  for (auto &t : tasks) cin >> t;
  for (auto &t : times) cin >> t;
  sort(tasks.begin(), tasks.end());
  sort(times.begin(), times.end());
  int i = n - 1, j = m - 1;
  int res = 0;
  while (i >= 0 && j >= 0) {
    int task = tasks[i], time = times[j];
    if (task <= time) {
      --i, --j;
      ++res;
    } else --i;
  }
  cout << res << endl;
  return 0;
}
