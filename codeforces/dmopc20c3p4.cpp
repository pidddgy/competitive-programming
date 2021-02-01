#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

// const int maxn = 5005;
const int maxn = 800;

int a[maxn];
int psa[maxn];

int dp[maxn][maxn][2];
int suf[maxn][maxn][2];
int pre[maxn][maxn][2];

int query(int l, int r) {
    int res = psa[r];
    if(l-1 >= 0) res -= psa[l-1];

    return res; 
    // return psa[r]-psa[l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1]+a[i];
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = i; j >= 1; j--) {
            sum += a[j];
            // 0
            // stay less than or equal to
            int l = 0, r = j-1;
            int lgood = -1;

            // how far should we go back to ensure that 
            // lgood -> j-1 is >= j..i
            while(l <= r) {
                int mid = (l+r)/2;

                if(query(mid, j-1) >= sum) {
                    l = mid+1;
                    lgood = mid;
                } else {
                    r = mid-1;
                }
            }

            if(j == 1) lgood = 0;

            if(lgood != -1) {
                cerr << j << " " << i << " maximum range " << lgood << " " << j-1 << endl;
                watch(pre[lgood][j-1][0])
                watch(dp[j][i][0])
                dp[j][i][0] = max(dp[j][i][0], pre[lgood][j-1][0]+1);
                watch(dp[j][i][0])
            }


            // do 1
            // must be bigger than or equal to last
            l = 0, r = j-1;
            lgood = -1;

            // what is the most far back we can go to ensure that lgood.j-1 <= j..i
            // OR how far forward should we go to ensure that lgood.j-1 <= j..i
            // we want to make it as far right as possible
            cerr << j << " " << i << endl;
            watch(sum)
            while(l <= r) {
                int mid = (l+r)/2;
                cerr << "trying " << mid << endl;
                watch(query(mid, j-1));

                if(query(mid, j-1) <= sum) {
                    r = mid-1;
                    lgood = mid;
                } else {
                    l = mid+1;
                }
            }

            if(j == 1) lgood = 0;


            if(lgood != -1) {
                cerr << j << " " << i << " range to be increasing is " << 0 << " " << lgood << endl;
                dp[j][i][1] = max(dp[j][i][1], suf[lgood][j-1][1]+1);
                dp[j][i][1] = max(dp[j][i][1], suf[lgood][j-1][0]+1);
            }

            if(i == n)
            ans = max({ans, dp[j][i][0], dp[j][i][1]});
        }

        for(int j = 0; j <= i; j++) {
            pre[j][i][0] = dp[j][i][0];
            pre[j][i][1] = dp[j][i][1];
            if(j > 0) {
                pre[j][i][0] = max({pre[j-1][i][0], dp[j][i][0]});
                pre[j][i][1] = max({pre[j-1][i][1], dp[j][i][1]});
            }
        }

        for(int j = i; j >= 0; j--) {
            suf[j][i][0] = dp[j][i][0];
            suf[j][i][1] = dp[j][i][1];
            if(j < i) {
                suf[j][i][0] = max({suf[j+1][i][0], dp[j][i][0]});
                suf[j][i][1] = max({suf[j+1][i][1], dp[j][i][1]});
            }
        }
    }

    watch(suf[1][1][0])
    watch(dp[1][1][0])
    watch(dp[2][2][0])
    watch(dp[3][3][1])

    

    cout << ans << endl;
}

/*

dp[last index][index][inc]
suffix max dp[last index][index][inc]

if i go back x amount, what is the best i can choose from all j?

binary search


300 000 000



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?