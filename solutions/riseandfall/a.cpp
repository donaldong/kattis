#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string num;
		cin >> num;
		char maxDigit = num[0];
		bool haveFound = false, couldRise = false;
		for (int i = 1; i < num.size(); ++i) {
			if (!haveFound && num[i] < maxDigit) {
        haveFound = true, maxDigit = num[i];
        continue;
      }

			if (haveFound) {
				if (!couldRise) maxDigit = min(maxDigit, num[i]);
        if (num[i] > maxDigit) couldRise = true;
				num[i] = maxDigit;
			} else { // !haveFound && num[i]  >= maxDigit
				maxDigit = max(maxDigit, num[i]);
			}
		}
		cout << num << endl;
	}
	return 0;
}

