#include<bits/stdc++.h>
using namespace std;

vector<int> ratings;
int dfs(int start, int k) {
	if (start+1>= ratings.size()) return 0;
  int r = (ratings.size() - start)/2;
	int mid = start+r;
	int res = 0;
  for (int i = start, j = mid; i < mid; ++j) {
    while (i < mid && ratings[i]+k<ratings[j]) {
      ++i;
    }
    if (i < mid && ratings[i]+k>=ratings[j]) ++i, ++res;
  }
#ifdef DEBUG
  printf("start=%d, mid=%d, right=%d, res=%d\n", start,mid,mid+r,res);
#endif
	return res + dfs(mid, k);
}

int main() {
	int n, k;
	cin >> n >> k;
	ratings.resize(1<<n);
	for (int &rating : ratings) cin >> rating;
	sort(ratings.begin(), ratings.end());
	cout << dfs(0, k) << endl;
	return 0;
}
