// https://codeforces.com/contest/1368/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define fi first
#define se second

int cnt[15];

const int len = 10;
const string S = ".codeforces";
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int ways = 1;
    
    for(int i = 1; i <= len; i++) {
        cnt[i]++;
    }

    int ind = 1;
    while(ways < k) {
        cnt[ind]++;

        int nw = 1;

        for(int i = 1; i <= len; i++) {
            nw *= cnt[i];
        }

        ways = nw;

        ind++;
        if(ind == len+1) ind=1;
    }

    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= cnt[i]; j++) cout << S[i];
    }
    cout << endl;
}
