// https://dmoj.ca/problem/dmopc16c1p3

#include <bits/stdc++.h>
#define MAXN 10000
#define db double
using namespace std;

db dp[MAXN];

int main() {
    fill(dp, dp+MAXN, 999999999999);
    int N;
    cin >> N;

    db a[N+1];
    for(int i = 1; i <= N; i++) cin  >> a[i];

    a[0] = 0;
    dp[0] = 0; 

    
    for(int i = 1; i <= N; i++) {
        dp[i] = a[i] + dp[i-1];
        
        if(i-2>=0) {
            dp[i] = min(dp[i], dp[i-2] +  a[i]+a[i-1] - (min(a[i], a[i-1]) / 2.0));
        }
        if(i-3>=0) {
            dp[i] = min(dp[i], dp[i-3] + a[i]+a[i-1]+a[i-2] - min(a[i], min(a[i-1], a[i-2])));
        }

    }


    cout << fixed << setprecision(1) << dp[N] << endl;
}
