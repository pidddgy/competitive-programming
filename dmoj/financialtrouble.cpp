// https://dmoj.ca/problem/dmopc19c4p5

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N, M, Q;
    cin >> N >> M >> Q;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    while(Q--) {
        int l, r;
        cin >> l >> r;

        int doll = M;
        int borrow = 0;
        for(int i = l; i <= r; i++) {
            doll += a[i];
            if(doll < 0) {
                doll = 0;
                borrow++;
            }
        }

        cout << doll << " " << borrow << endl;
    }
}