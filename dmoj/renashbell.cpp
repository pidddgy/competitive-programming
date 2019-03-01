// https://dmoj.ca/problem/stnbd1

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int a;
    cin >> a;
    for(int i = 0; i < N-1; i++) {
        int b;
        cin >> b;
        if(a<=b) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
