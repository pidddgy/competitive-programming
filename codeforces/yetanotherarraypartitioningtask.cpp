// https://codeforces.com/contest/1114/problem/B

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'


    int n, m, k;
    cin >> n >> m >> k;

    pii a[n+1];    

    for(int i = 1; i <= n; i++) {
        int _;
        cin >> _;

        a[i] = mp(_, i);
    }

    sort(a+1, a+n+1, greater<pii>());

    int greatest[(m*k)+1];
    
    int sum = 0;
    for(int i = 1; i <= m*k; i++) {
        greatest[i] = a[i].se;
        sum += a[i].fi;
    }

    sort(greatest+1, greatest+(m*k)+1);

    cout << sum << endl;
    for(int i = 1; i <= k-1; i++) {
        cout << greatest[i*m] << " ";
    }
    cout << endl;
}