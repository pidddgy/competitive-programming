// http://codeforces.com/contest/1195/problem/C

#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;

ll top[maxn];
ll bot[maxn];
ll cumtop[maxn];
ll cumbot[maxn];
int main() {
    #define int long long
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> top[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> bot[i];
    }

    cumtop[n] = top[n];
    cumbot[n] = bot[n]; 

    cumtop[n-1] = top[n-1] + bot[n];
    cumbot[n-1] = bot[n-1] + top[n];

    // we never skip 2 or more
    // so either skip 0, or 1
    for(int i = n-2; i >= 1; i--) {
        cumtop[i] = top[i] + max(cumbot[i+1], cumbot[i+2]);
        cumbot[i] = bot[i] + max(cumtop[i+1], cumtop[i+2]);
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << cumtop[i] << " ";
    // }
    // cout << endl;

    // for(int i = 1; i <= n; i++) {
    //     cout << cumbot[i] << " ";
    // }
    // cout << endl;

    cout << max(cumtop[1], cumbot[1]) << endl;


}