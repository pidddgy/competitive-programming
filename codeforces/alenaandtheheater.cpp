// https://codeforces.com/contest/940/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define cerr if(false) cerr
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    string bprime;
    cin >> bprime;

    bprime = "."+bprime;
    int bp[n+1];
    for(int i = 1; i <= n; i++) bp[i] = bprime[i]-'0';

    int l = -1e9;
    int r = 1e9;
    
    int b[n+1];
    for(int i = 1; i <= 4; i++) b[i] = 0;

    for(int i = 5; i <= n; i++) {
        cerr << "currently on index " << i << endl;
        if(bp[i] != b[i-1]) {
            if(bp[i] == 1 and b[i-1] == 0) {
                // force switch to 1
                cerr << "forcing switch to 1" << endl;
                int ma = -INT_MIN;
                for(int j = 0; j <= 4; j++) {
                    watch(i-j)
                    watch(a[i-j])
                    ma = max(ma, a[i-j]);
                }
                watch(ma)
                l = max(l, ma+1);
                watch(l)
            } else {
                // force switch to 0
                cerr << "forcing switch to 0" << endl;
                int mi = INT_MAX;
                for(int j = 0; j <= 4; j++) {
                    mi = min(mi, a[i-j]);
                }

                r = min(r, mi-1);
                watch(r)
            }
        }

        b[i] = bp[i];
    }

    cout << l << " " << r << endl;
}