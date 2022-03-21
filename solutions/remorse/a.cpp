#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string line;
  getline(cin, line);
  vector<int> freq(26);
  int letters = 0;
  for (char c : line) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z') ++letters, ++freq[c-'a'];
  }

  sort(freq.rbegin(), freq.rend());
  long long res = 0;
  int i = 0;

  vector<string> base{".","---"};
  unordered_set<string> codes{".", "---"};
  while (codes.size() <= 256) {
    unordered_set<string> codes2 = codes;
    for (string c : codes) for (string c2 : base) {
      codes2.insert(c+' '+c2);
      codes2.insert(c2+' '+c);
    }
    swap(codes, codes2);
  }
#ifdef DEBUG
  for (auto& code : codes) cout << code << endl;
#endif
  i = 0;
  vector<int> lens(codes.size());
  for (auto& code : codes) lens[i++]=code.size();
  sort(lens.begin(), lens.end());

  i = 0;
  for (int f : freq) {
    int len = lens[i++];
#ifdef DEBUG
    printf("f=%d, len=%d\n", f,len);
#endif
    res += f*len;
  }
  res += (letters-1)*3;
  cout << res << endl;
  return 0;
}
