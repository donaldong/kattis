#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
    int N;
    cin >> N;
    int t = 1;
    while (N--) {
        int P, K, L;
        cin >> P >> K >> L;
        vector<int> V(L);
        for (int &n : V) cin >> n; 
        sort(V.rbegin(), V.rend());
        ull res = 0;
        for (int i = 0; i < V.size(); ++i) {
            res += (i / K + 1) * V[i];
        }
        cout << "Case #" << t++ << ": " << res << endl;
    }
    return 0;
}
