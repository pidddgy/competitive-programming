// http://codeforces.com/contest/1204/problem/D1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int main() {
    string s;
    cin >> s;
    int N = s.size();
    s = "."+s;

    int dp[2000];
    for(int i = 0; i < 2000; i++) dp[i] = 1;

    int subseq = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(s[i] >= s[j]) {
                // cout << "HI" << endl;
                dp[i] = max(dp[i], dp[j]+1);
            }
            subseq = max(subseq, dp[i]);

        }
    }

    // for(int i = 1; i <= N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    

    //watch(subseq)

    string cute;
    for(int i = 1; i <= subseq; i++) {
        cute = cute+"0";
    }

    while(cute.size() != N) {
        cute = "1"+cute;
    }

    cout << cute << endl;

    
}

// 1111111110000000000000