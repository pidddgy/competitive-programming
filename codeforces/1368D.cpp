// https://codeforces.com/contest/1368/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 200500;

int a[maxn];
int cnt[30];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        for(int b = 0; b <= 21; b++) {
            int exp = 1LL << b;

            if(a[i]&exp) {
                // cerr << "incrementing " << exp << endl;
                cnt[b]++;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int num = 0;
        for(int j = 0; j <= 20; j++) {
            if(cnt[j]) {
                num += 1LL<<j;
                cnt[j]--;
            }
        }

        ans += num*num;
    }

    cout << ans << endl;


}
