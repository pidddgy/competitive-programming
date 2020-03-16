// https://dmoj.ca/problem/ccc19s4

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N, K;
    cin >> N >> K;

    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a+N);

    if(K >= N) {
        cout << a[N-1] << endl;
        return 0;
    }
    cout << a[N-1] + a[N-2] << endl; 
}