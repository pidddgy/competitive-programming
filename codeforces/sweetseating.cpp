// http://codeforces.com/contest/1253/problem/C


#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
   int N, M;
   cin >> N >> M;

    int a[N+1];
    
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    } 

    sort(a+1, a+N+1);
    int psa[N+1];
    psa[0] = 0;
    psa[1] = a[1];

    for(int i = 2; i <= N; i++) {
       psa[i] = a[i] + psa[i-1]; 
    }

    int dp[N+1];
    for(int i = 1; i <= N; i++) {
        dp[i] = 0;
        dp[i] = psa[i];
        if(i-M > 0) dp[i] -= psa[i-M];
        if(i-M > 0) dp[i] += dp[i-M]*2;
        if(i-M-M > 0) dp[i] -= dp[i-M-M];

        cout << dp[i] << " ";
    }
    cout << endl;
}