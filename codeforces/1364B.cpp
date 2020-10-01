// https://codeforces.com/contest/1364/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;
int a[maxn];
bool needed[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            needed[i] = true;
        }      

        for(int i = 2; i <= n-1; i++) {
            if(a[i-1] <= a[i] and a[i] <= a[i+1]) {
                needed[i] = false;
            } else if(a[i-1] >= a[i] and a[i] >= a[i+1]) {
                needed[i] = false;
            }
        }

        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(needed[i]) ans.emplace_back(a[i]);
        }

        cout << ans.size() << endl;
        for(int x: ans) {
            cout << x << " ";
        }
        cout << endl;

        for(int i = 1; i <= n; i++) {
            a[i] = 0;
            needed[i] = true;
        }              
    }
}
