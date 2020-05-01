// https://codeforces.com/contest/1341/problem/C    

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        map<int, int> index;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            index[a[i]] = i;
        }
        
        string ans = "Yes";
        int l = 1;
        int b = n;

        while(l < n) {
            int ind = index[l];
            cerr << "looking for " << l << endl;
            watch(ind)
            watch(b)
            for(int i = ind; i <= b; i++) {
                watch(i)
                watch(l)
                if(a[i] != l) {
                    ans = "No";
                    break;
                }
                l++;
                
                if(ans == "No") break;
            }
            if(ans == "No") break;

            b = ind-1;
            // l++;
            cerr << "now looking for " << l << endl;
        }

        cout << ans << endl;
    }
}

/*
1
4
2 4 3 1
*/