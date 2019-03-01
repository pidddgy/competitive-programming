// https://dmoj.ca/problem/ccc07j5

#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
int main() {
    #define int long long
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;

    vector<int> M = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int N;
    cin >> N;
    vector<int> cute;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        M.eb(a);
    }

    int dp[M.size()]; for(int i = 0; i < M.size(); i++) dp[i] = 0;
    dp[0] = 1;
    sort(M.begin(), M.end());

    for(int i = 0; i < M.size()-1; i++) {
        for(int j = 0; j < M.size(); j++) {
            if(M[j]-M[i] >= A && M[j]-M[i] <= B) {
                dp[j] += dp[i];
            }
        }
    }

    cout << dp[M.size()-1] << endl;
}
