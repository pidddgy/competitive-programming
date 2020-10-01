// https://codeforces.com/contest/1359/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;

        int a[k+1];
        for(int i = 1; i <= k; i++) {
            a[i] = 0;
        }

        while(a[1] < n/k and m) {
            a[1]++;
            m--;
        }

        while(m) {
            for(int i = 2; i <= k; i++) {
                if(m and a[i] < n/k) {
                    a[i]++;
                    m--;
                }
            }
        }

        int ma = 0;
        int macnt = 0;
        bool found = false;
        for(int i = 2; i <= k; i++) {
            if(a[i] >= a[1]) {
                cout << 0 << endl;
                found = true;
                break;
            }
            ma = max(ma, a[i]);
        }

        if(!found) {
            cout << a[1]-ma << endl;
        }

        // for(int i = 1; i <= k; i++) {
        //     cerr << a[i] << " ";
        // }
        // cerr << endl;


        // int per = n/k;

        // if(m > (n-1)*per) {
        //     cout << 0 << endl;
        // } else {
            
        //     cout << m-per << endl;
        // }
    }
}
