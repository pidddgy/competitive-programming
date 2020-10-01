// https://dmoj.ca/problem/usaco20janb3

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
int K, N;

// sum of arithmetic sequence
int sum(int a, int d, int n) {
    return (n*(2*a + (n-1)*d))/2;
}
void solve(int X) {
    // deescalate
    // bsearch for how for up you can go
    int l = X;
    int r = 1e9;
    int ans = INT_MAX;

    while(l <= r) {
        int m = (l+r)/2;

        int dup = sum(1, 1, m);

        // down does not include the last term of m
        int ddown = sum(m-1, -1, m-X);
        
        // how many terms to add to middle?
        int rem = K-dup-ddown;
        int mid = rem/m;
        rem -= m*mid;

        // how many terms to add to end?
        int end = (rem+K-1)/K;

        if(dup+ddown <= K) {
            ans = min(ans, (2*m)-X+mid+end);
            l = m+1;
        } else {
            r = m-1;
        }
    }

    // don't deescalate
    int ans2 = INT_MAX;

    l = 1;
    r = X;

    while(l <= r) {
        int m = (l+r)/2;

        int dup = sum(1, 1, m);
        int rem = K-dup;
        int end = (rem+m-1)/m;

        if(dup <= K) {
            ans2 = m+end;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << min(ans, ans2) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;

    for(int i = 1; i <= N; i++) {
        int X;
        cin >> X;

        solve(X);
    }
}
