// https://codeforces.com/problemset/problem/4/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N-1; i++) {
        if(i % 2 == 0 && (N-i) % 2 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
