// https://codeforces.com/problemset/problem/946/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 510;

int N, M, K;

// rem = min hours needed on day i if you remove j
int a[maxn][maxn], dp[maxn][maxn], rem[maxn][maxn];

// number of 1s in row i
int cnt[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = rem[i][j] = INT_MAX;
        }
    }

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        string row;
        cin >> row;

        for(int j = 1; j <= M; j++) {
            a[i][j] = row[j-1]-'0';
            cnt[i] += a[i][j];
        }
    }    

    for(int i = 1; i <= N; i++) {
        rem[i][cnt[i]] = 0;
        // remove 
        for(int j = 1; j <= M; j++) {
            int o = 0;
            for(int k = j; k <= M; k++) {
                o += a[i][k];
                rem[i][cnt[i]-o] = min(rem[i][cnt[i]-o], (k-j)+1);

                if(o == 0) rem[i][cnt[i]-o] = 0;
            }
        }
    }


    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            // k = how many we remove on current
            for(int k = 0; k <= min(j, cnt[i]); k++) {
                dp[i][j] = min({dp[i][j], dp[i-1][j-k] + rem[i][k]});
                if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[N][K] << endl;
}

/*

think about "spending" removals

do n^3 preprocess
    -> if i spend x removals on this day, what is the min number of hours I have to use?

dp[i][j] = day i, used j removals -> hours spent

for i in 1...N
    for j in 1...K
        for k in 1...(num hours in this row)
            transition from dp[i][j-1] and dp[i-1][j-k]

total time complexity: n^3
    - 125 000 000 operations
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
