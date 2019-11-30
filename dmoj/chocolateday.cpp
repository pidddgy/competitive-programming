// https://dmoj.ca/problem/rgpc18p3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;

ll d[1000006];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N, T;
    cin >> N >> T;

    for(int i = 1; i <= T; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        d[a] += c;
        d[b+1] -= c;
    }

    for(int i = 1; i <= N; i++) {
        d[i] += d[i-1];
    }

    ll L;
    cin >> L;
    
    ll l = 1;
    ll r = 1;
    ll s = 0;
    ll maxv = 0;

    while(l <= N) {
        bool m = false;
        while(r <= N-1) {
            if(s + d[r+1] <= L) {
                s += d[r+1];
                m = true;
                r++;
            }
            else break;
        }

        if(m) {
            maxv = max(maxv, r-l+1);    
            s -= d[l];
        }
        
        l++;
    }

    cout << maxv << "\n";
}

