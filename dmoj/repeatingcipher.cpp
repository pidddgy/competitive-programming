// http://codeforces.com/contest/1095/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; string aqt;
    cin >> N;
    cin.ignore();
    getline(cin, aqt);

    for(int i = 0, incr = 1; i < N; i+= incr, incr++) {
        cout << aqt[i];
    }
    cout << "\n";
}
