// https://codeforces.com/contest/1326/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int b[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> b[i];
    }

    int a[N+1];
    a[1] = b[1];
    int ma = a[1];
    for(int i = 2; i <= N; i++) {
        a[i] = b[i]+ma;
        ma = max(ma, a[i]);
    }

    for(int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}