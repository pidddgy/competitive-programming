// https://codeforces.com/contest/859/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    int T[N+1];
    int noT[N+1];

    T[N] = a[N];
    noT[N] = 0;

    for(int i = N-1; i >= 1; i--) {
        if(a[i] + noT[i+1] > T[i+1]) {
            T[i] = a[i]+noT[i+1];
            noT[i] = T[i+1];
        } else {
            T[i] = T[i+1];
            noT[i] = a[i]+noT[i+1];
        }
    }

    cout << noT[1] << " " << T[1] << endl;
}