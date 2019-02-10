#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
vs cmds(1001, "000");
vi REG(11, 0);

string cmd_string(int n) {
  string res = to_string(n);
  while (res.size() != 3) res = '0' + res;
#ifdef DEBUG
  printf("%d => %s\n", n, res.c_str());
#endif
  return res;
}

int exec_cmd(int i) {
  int d, n, s, a;
  string cmd = cmds[i];
  d = cmd[1] - '0', n = cmd[2] - '0';
  switch (cmd[0]) {
    case '2':
      REG[d] = n;
      break;
    case '3':
      REG[d] += n;
      REG[d] %= 1000;
      break;
    case '4':
      REG[d] *= n;
      REG[d] %= 1000;
      break;
    case '5':
      s = n;
      REG[d] = REG[s];
      break;
    case '6':
      s = n;
      REG[d] += REG[s];
      REG[d] %= 1000;
      break;
    case '7':
      s = n;
      REG[d] *= REG[s];
      REG[d] %= 1000;
      break;
    case '8':
      a = n;
      REG[d] = stoi(cmds[REG[a]]);
      break;
    case '9':
      s = d, a = n;
      cmds[REG[a]] = cmd_string(REG[s]);
      break;
    default:
      s = n;
      if (REG[s] != 0) return REG[d];
  }
  return i + 1;
}

int main() {
  ios::sync_with_stdio(0);

  int pos = 0, res = 1, i = 0;
  while (getline(cin, cmds[i++]));
  while (cmds[pos][0] != '1') {
    pos = exec_cmd(pos);
    ++res;
  }
  printf("%d\n", res);
  return 0;
}
