// https://dmoj.ca/problem/gfssoc2j4

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    int psa[N];
    cin >> psa[0];
    for(int i = 1; i < N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a = a-1; b = b-1;
        if(a == 0)
            cout << psa[N-1] - psa[b] << "\n";
        else
            cout << psa[N-1] - (psa[b] - psa[a-1]) << "\n";
    }
}
