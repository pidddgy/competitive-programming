// https://codeforces.com/contest/1364/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;
int a[maxn], ans[maxn];
set<int> nums, nums2, S;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    S.emplace(0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        S.emplace(a[i]);
    }

    for(int i = 0; i <= 1e6; i++) {
        if(!S.count(i)) {
            nums.emplace(i);
        }
        nums2.emplace(i);
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i-1]) {
            ans[i] = a[i-1];
        } else if(nums.size()) {
            ans[i] = *nums.begin();
            nums.erase(*nums.begin());
        } else {
            ans[i] = 1e6;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(nums2.count(ans[i])) {
            nums2.erase(ans[i]);
        }

        if(a[i] != *nums2.begin()) {
            // watch(a[i])
            // watch(*nums2.begin());
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
