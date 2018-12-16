// https://dmoj.ca/problem/dmopc14c2p4

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, Q; cin >> N;
    int pArr[N];
    
    cin >> pArr[0];
    for(int i = 1; i < N; i++) {
        cin >> pArr[i];
        pArr[i] += pArr[i-1];
    }

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if(a != 0)
            cout << pArr[b] - pArr[a-1] << "\n";
        else
            cout << pArr[b] << "\n";
    } 
}
