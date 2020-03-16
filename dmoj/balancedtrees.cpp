// https://dmoj.ca/problem/ccc18s4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define int long long
using namespace std;

unordered_map<int, int> dp;

int f(int n) {
    if(dp.find(n) != dp.end()) {
        return dp[n];
    }

    if(n == 1 or n == 2) {
        dp[n] = 1;
        return dp[n];
    }
    int ans = 0;
    for(int k = 2; k <= n; k++) {
        ans += f(n/k);
    }

    dp[n] = ans;
    return dp[n];
}

signed main() {
    int N;
    cin >> N;

    cout << f(N) << endl;

    
}