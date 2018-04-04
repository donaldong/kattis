#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct word;
struct cat {
  vector<word*> words;
  string val;
};
struct word {
  vector<cat*> cats;
  string val;
};
int main() {
  int N;
  cin >> N;
  unordered_map<string, cat> C;
  unordered_map<string, word> W;
  while (N--) {
    string c;
    int n;
    cin >> c >> n;
    C[c].val = c;
    while (n--) {
      string w;
      cin >> w;
      W[w].val = w;
      W[w].cats.push_back(&C[c]);
    }
  }
  string line;
  unordered_map<string, int> count;
  while (cin >> line) {
    if (W.find(line) != W.end()) {
      for (auto c : W[line].cats) {
        count[c->val]++;
      } 
    }
  }
  int maxcount = 0;
  vector<string> res;
  for (auto &entry : count) maxcount = max(maxcount, entry.second);
  for (auto &entry : count) {
    if (entry.second == maxcount) {
        res.push_back(entry.first);
    }
  }
  if (res.empty()) {
    for (auto &entry : C) res.push_back(entry.first);
  }
  sort(res.begin(), res.end());
  for (string r : res) cout << r << endl;
}
