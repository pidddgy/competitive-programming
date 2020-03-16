// https://codeforces.com/problemset/problem/492/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
#define ld long double
using namespace std;
int main() {
    ll n, l;
    cin >> n >> l;

    ll a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    sort(a, a+n);

    ld ma = max(a[0], abs(a[n-1]-l));
    for(ll i = 0; i < n-1; i++) {
        ld d = a[i+1] - a[i];
        ma = max(ma, d/2.0);
    }

    cout << fixed << setprecision(9) << ma << endl;


}

