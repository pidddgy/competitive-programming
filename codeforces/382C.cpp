// https://codeforces.com/contest/382/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

const int maxn = 100500;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);

    set<int> ans;

    if(n == 1) {
        cout << -1 << endl;
        return 0; 
    } else if(n == 2) {
        ans.emplace(a[1]-(a[2]-a[1]));
        if((a[2]-a[1])%2 == 0) {
            ans.emplace(a[2]-((a[2]-a[1])/2));
        }
        ans.emplace(a[2]+(a[2]-a[1]));
    } else if(n == 3) {

        if((a[3]-a[2])%2==0)
        if((a[2]-a[1]) == (a[3]-a[2])/2) {
            ans.emplace(a[2]+((a[3]-a[2])/2));
        }

        if((a[2]-a[1])%2==0)
        if((a[3]-a[2]) == (a[2]-a[1])/2) {
            ans.emplace(a[2]-((a[2]-a[1])/2));
        }

        if(a[3]-a[2] == a[2]-a[1]) {
            ans.emplace(a[1]-(a[3]-a[2]));
            ans.emplace(a[3]+(a[3]-a[2]));
        }
    } else {
        map<int, int> cnt;
        for(int i = 2; i <= n; i++) {
            cnt[a[i]-a[i-1]]++;
        }

        if(cnt.size() == 1) {
            ans.emplace(a[1]-(a[3]-a[2]));
            ans.emplace(a[n]+(a[3]-a[2]));
        } else if(cnt.size() > 2) {
            cout << 0 << endl;
            return 0;
        } else {
            for(int i = 2; i <= n; i++) {
                if(cnt[a[i]-a[i-1]] == 1) {
                    int d;
                    if(i == 2) d = a[n]-a[n-1];
                    else d = a[2]-a[1];
                    if((a[i]-a[i-1])%2==0 and ((a[i]-a[i-1])/2) == d) {
                        ans.emplace(a[i]-((a[i]-a[i-1])/2));
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}