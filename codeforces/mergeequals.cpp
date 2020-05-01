// https://codeforces.com/contest/962/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define int long long
#define endl '\n'
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> have;
    for(int i = 1; i <= N; i++) {
        while(have.count(a[i]) and have[a[i]] != -1) {
            a[have[a[i]]] = -1;
            have[a[i]] = -1;
            a[i] *= 2;
        }
        have[a[i]] = i;
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        cnt += a[i]!=-1;
    }

    cout << cnt << endl;
    for(int i = 1; i <= N; i++) {
        if(a[i] != -1) cout << a[i] << " ";
    }
    cout << endl;

}