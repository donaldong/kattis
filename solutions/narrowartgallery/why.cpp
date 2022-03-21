#include <vector>
#include <iostream>
using namespace std;

vector<vector<vector<int>>> T;

int main() {
    for (int i = 0; i < 5; ++i) {
        T = vector<vector<vector<int>>>(200, vector<vector<int>>(201, vector<int>(3, -1)));
        cout << T.size() << endl;
    }
    return 0;
}
