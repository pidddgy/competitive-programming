// https://codeforces.com/contest/274/problem/A

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    #define cerr if(false) cerr
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1, greater<int>());
    set<int> have;

    for(int i = 1; i <= n; i++) {
        cerr << "on " << a[i] << endl;
        if(!have.count(a[i]*k)) {
            cerr << "adding" << endl;
            have.emplace(a[i]);
        }
    }

    cout << have.size() << endl;
}