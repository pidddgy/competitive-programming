// http://codeforces.com/problemset/problem/1184/B1

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int s, b;
    cin >> s >> b;

    int a[s+1];
    for(int i = 1; i <= s; i++) {
        cin >> a[i];
    }

    pii base[b+1];
    for(int i = 1; i <= b; i++) {
        cin >> base[i].fi >> base[i].se;
    }

    sort(base+1, base+b+1);

    int psa[b+1];
    psa[1] = base[1].se;
    for(int i = 2; i <= b; i++) {
        psa[i] = psa[i-1] + base[i].se;
    }

    for(int i = 1; i <= s; i++) {
        int l = 1;
        int r = b;
        int lastgood = -1;

        while(l <= r) {
            int m = (l+r)/2;

            if(base[m].fi <= a[i]) {
                l = m+1;
                lastgood = m;
            } else {
                r = m-1;
            }
        }

      //  if(lastgood == -1) cout << 0 << " ";
        cout << psa[lastgood] << " ";
    }

    cout << endl;



    
}

