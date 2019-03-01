// https://dmoj.ca/problem/dpk

#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    int dp[K+1]; for(int i = 0; i < K+1; i++) dp[i] = 0;

    for(int i = 1; i < K+1; i++) {
        for(int j = 0; j < N; j++) {
            if(i - a[j] >= 0) {
                if(dp[i - a[j]] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    if(dp[K]) cout << "First" << endl;
    else cout << "Second" << endl;

}
