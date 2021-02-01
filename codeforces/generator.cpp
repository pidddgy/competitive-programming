#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    int n = mt()%4+1;
    cout << n << endl;

    for(int i = 1; i <= n; i++) {
        cout << mt()%10+1 << " ";
    }
    cout << endl;
}