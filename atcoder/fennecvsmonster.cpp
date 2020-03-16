// https://atcoder.jp/contests/abc153/tasks/abc153_c

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N, K;
    cin >> N >> K;

    int a[N+1];
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        int b;
        cin >> b;

        sum += b;
        a[i] = b;
    }

    sort(a+1, a+N+1, greater<int>());
    for(int i = 1; i <= min(N,K); i++) {
        sum -= a[i];
    }

    cout << sum << endl;
}