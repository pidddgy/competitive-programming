// http://codeforces.com/contest/1178/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1];

    int total = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
    }

    vector<int> ans;
    ans.emplace_back(1);
    for(int i = 2; i <= n; i++) {
        if(a[i]*2 <= a[1]) {
            // cout << "emplacing " << i << endl;
            ans.emplace_back(i);
        }
    }

    int sum = 0;
    for(auto x: ans) {
        sum += a[x];
    }
    // watch(sum)


    if(sum <= total / 2) {
        cout << 0 << endl;
        return 0;
    }


    cout << ans.size() << endl;
    for(auto x: ans) cout << x << " ";
    cout << endl;


}