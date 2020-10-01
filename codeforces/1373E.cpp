// https://codeforces.com/contest/1373/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

int sum(int n) 
    {  
    int res = 0; 
    while (n != 0) { 
        res += n % 10;
        n /= 10;
    }  
    return res; 
} 

int n, k;
int f(int num) {
    watch(num)
    watch(k)
    int res = num;
    for(int j = 1; j <= k-1; j++) {
        res += sum(num+j);
        cerr << "adding " << num+j << endl;
    }

    return res;
}

int init[3];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        int ans = LLONG_MAX;
        
        int last = 0;
        for(int i = 10; i >= 1; i--) {
            int s = f(i);
            if(s == n) ans = i;
            last = max(last, s);
        }

        int initInd = 1; 
        for(int i = 10; i <= 50; i++) {
            int s = f(i);
            if(s > last) {
                init[initInd] = i;
                last = s;
                initInd++;

                if(initInd == 3) break;
            }
        }

        watch(init[1])
        watch(init[2])

        init[1] = init[2] = 0;

        int d = init[2]-init[1];

        int l = 1;
        int r = 2e9;

        while(l <= r) {
            int m = (l+r)/2;

            int ind = init[1]+(d*m);

            int s = f(ind);

            if(s > n) {
                r = m-1;
            } else if(s < n) {
                l = m+1;
            } else {
                ans = m;
            }
        }

        if(ans == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }


    
}