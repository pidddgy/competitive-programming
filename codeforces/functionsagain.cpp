// https://codeforces.com/contest/788/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int odd[n+1];
    int even[n+1];
    odd[n] = 0;
    even[n] = 0;
    for(int i = 1; i <= n-1; i++) {
        odd[i] = abs(a[i+1]-a[i]);
        even[i] = abs(a[i+1]-a[i]);
        if(i % 2 == 0) {
            odd[i] *= -1;
        } else {
            even[i] *= -1;
        }
    }

    int dpodd[n+1];

    dpodd[1] = odd[1];
    for(int i = 2; i <= n; i++) {
        dpodd[i] = max(odd[i], odd[i]+dpodd[i-1]);
    }
   
    int dpeven[n+1];
    dpeven[1] = even[1];
    for(int i = 2; i <= n; i++) {
        dpeven[i] = max(even[i], even[i]+dpeven[i-1]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max({ans, dpodd[i], dpeven[i]});
    }

    cout << ans << endl;
}