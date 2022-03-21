#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int diff = m - n;
  if (diff > 1)
    printf("Dr. Chaz will have %d pieces of chicken left over!\n", diff);
  else if (diff == 1)
    printf("Dr. Chaz will have %d piece of chicken left over!\n", diff);
  else if (diff == -1) 
    printf("Dr. Chaz needs 1 more piece of chicken!");
  else
    printf("Dr. Chaz needs %d more pieces of chicken!\n", -diff);
  return 0;
}
