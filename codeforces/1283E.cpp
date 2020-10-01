// https://codeforces.com/contest/1283/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 300800;

int a[maxn];
int amtcpy[maxn];
int amt[maxn];
int dp[maxn];
int ans;

void reset() {
    ans = 0;
    for(int i = 0; i < maxn; i++) {
        amt[i] = amtcpy[i];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        amtcpy[a[i]]++;
    }

    reset();

    // get min houses
    for(int i = 1; i <= maxn-500; i++) {
        if(amt[i-1]) {
            amt[i-1] = amt[i] = amt[i+1] = 0;
            ans++;
        }
    }

    cout << ans << " ";

    reset();

    // get max houses
    for(int i = 1; i <= n; i++) {
        if(!amt[i-1] and amt[i]) {
            amt[i-1]++;
            amt[i]--;
        }
        if(amt[i]>1) {
            amt[i+1]++;
            amt[i]--;
        }
    }

    if(amt[n] > 1) {
        amt[n]--;
        amt[n+1]++;
    }

    for(int i = 0; i <= n+1; i++) {
        ans += (amt[i]>=1);
    }

    cout << ans << endl;


}


/*

12
3 4 5 5 5 7 7 9 9 9 10 12

*/