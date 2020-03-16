// http://codeforces.com/contest/1189/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int psa[N+1];
    for(int i = 0; i < N+1; i++) psa[i] = 0;

    for(int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int l, r;
        cin >> l >> r;

        cout << (psa[r] - psa[l-1]) / 10 << endl;
    }
}