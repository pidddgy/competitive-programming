// https://codeforces.com/contest/518/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long
const int maxn = 100500;

int at[maxn]; // element at pos i
int pos[maxn]; // pos of element i
int n, m, k;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        at[i] = a;
        pos[a] = i;
    }

    int ans = 0;
    while(m--) {
        int b;
        cin >> b;

        cerr << "adding " << ((pos[b]+k-1)/k) << " to ans" << endl;
        ans += ((pos[b]+k-1)/k);
        
        if(pos[b] == 1) continue;

        int temp = at[pos[b]-1];
        pos[temp] = pos[b];
        at[pos[b]-1] = b;
        cerr << "setting at at ind " << pos[b]-1 << " to " << b << endl;
        at[pos[b]] = temp;
        pos[b]--;


        for(int i = 1; i <= n; i++) {
            cerr << at[i] << " \n"[i==n];
        }

        for(int i = 1; i <= n; i++) {
            cerr << pos[i] << " \n"[i==n];
        }
        cerr<<endl;
    }

    cout << ans << endl;
}