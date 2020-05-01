// https://codeforces.com/contest/1278/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;


        int a[(n*2)+50];
        
        int c1 = 0;
        int c2= 0 ;
        for(int i = 1; i <= (n*2); i++) {
            cin >> a[i];
            if(a[i] == 1) c1++;
            if(a[i] == 2) c2++;
        }

        unordered_map<int, int> diff;

        diff[0] = 0;
        int cur = 0;

        for(int i = n+1; i <= 2*n; i++) {
            if(a[i] == 1) {
                cur++;
            } else {
                cur--;
            }

            if(!diff.count(cur)) {
                diff[cur] = i-n;
            }
        }

        int ans = INT_MAX;
        int orig = c1-c2;

        watch(orig)

        cur = 0;
        for(int i = n; i >= 1; i--) {
            if(a[i] == 1) {
                cur++;
            } else {
                cur--;
            }

            if(diff.count(orig-cur)) {
                ans = min(ans, n-i+1+diff[orig-cur]);
            }
        }

        if(diff.count(orig)) {
            ans = min(ans, diff[orig]);
        }

        cout << ans << endl;
    }
}

/*
1
3
1 2 1 1 2 1
*/