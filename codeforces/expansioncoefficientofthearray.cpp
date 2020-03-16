// http://codeforces.com/contest/1159/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    int ans = 2147483647;
    for(int i = 1; i <= N; i++) {
        ans = min(ans, a[i] / max(i-1, N-i));
    } 

    cout << ans << endl;
}
