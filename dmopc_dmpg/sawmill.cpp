// https://dmoj.ca/problem/dmopc14c2p3

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int aqt[N];
    int bqt[N];
    long long total = 0;

    for(int i = 0; i < N; i++) {
        cin >> aqt[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> bqt[i];
    }

    sort(aqt, aqt+N);
    sort(bqt, bqt+N, greater<int>());

    for(int i = 0; i < N; i++) {
        total += aqt[i] * bqt[i];
    }

    cout << total << endl;
}
