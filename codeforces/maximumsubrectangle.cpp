// https://codeforces.com/contest/1060/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    #define pii pair<int, int>
    #define fi first
    #define se second
    #define watch(x) cerr << (#x) << " is " << (x) << endl;
    #define cerr if(false) cerr
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    int b[m+1];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    int x;
    cin >> x;

    int ans = 0;

    unordered_map<int, int> mi;
    for(int i = 1; i <= n; i++) mi[i] = INT_MAX;
    for(int i = 1; i <= n; i++) {
        int cur = i;
        int asum = a[cur];
        while(cur <= n) {
            mi[cur-i+1] = min(mi[cur-i+1], asum);
            cur++;

            if(cur <= n)
            asum += a[cur];
        }
    }

    for(int i = 1; i <= n; i++) {
        int l = 1;
        int r = 1;

        int bsum = b[l];
        while(l <= m) {
            while(r <= m) {
                if((mi[i] * bsum) <= x) {
                    watch(i)
                    watch(l)
                    watch(r)
                    ans = max(ans, i * ((r-l)+1));
                    watch(ans)
                    cerr << endl;
                    r++;

                    if(r <= m)
                    bsum += b[r];
                } else break;
            }
            bsum -= b[l];
            l++;
        }
    }
    cout << ans << endl;
}

/*
            int l = 1;
            int r = 1;

            int bsum = b[l];
            while(l <= m) {
                while(r <= m) {
                    if((asum * bsum) <= x) {
                        ans = max(ans, (cur-i+1) * ((r-l)+1));
                    }
                    r++;
                    bsum += b[r];
                }
                bsum -= b[l];
                l++;
            }
            */