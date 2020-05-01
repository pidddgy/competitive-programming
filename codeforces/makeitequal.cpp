// https://codeforces.com/contest/1065/problem/C

#include <bits/stdc++.h>
#define maxh 200000
using namespace std;
int diff[maxh + 500];

int main() {
    int n, k;
    cin >> n >> k;

    int a[n+1];
    diff[0] = n;
    for(int i = 1; i <= n; i++) {
        int _;
        cin >> _;

        a[i] = _;
        diff[_]--;
    }

    for(int i = 1; i <= maxh; i++) {
        diff[i] += diff[i-1];
    }

    int ans = 0;
    int sum = 0;    
    for(int i = maxh; i >= 1; i--) {
        if(diff[i] == n) break;
        if(sum + diff[i] > k) {
           ans++;
           sum = diff[i]; 
        } else {
            sum += diff[i];
        }
    }

    if(sum) {
        ans++;
    }

    cout << ans << endl;
}