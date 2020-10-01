// https://codeforces.com/contest/1349/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
bool prime[200500];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 200500; i++) {
        prime[i] = true;
    }

    int n;
    cin >> n;
    
    for(int p = 2; p <= 200000; p++) {
        if(prime[p]) {
            for(int i = p*p; i <= 200000; i += p) {
                prime[i] = false;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= 200000; i++) {
        if(prime[i]) {
            primes.emplace_back(i);
        }
    }

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    for(int x: primes) {
        // watch(x)
        int mi = LONG_MAX;
        int smi = LONG_MAX;
        for(int i = 1; i <= n; i++) {
            int div = 0;
            int temp = a[i];

            while(temp%x==0) {
                div++;
                temp /= x;
            }

            // cerr << x << " appears in " << a[i] << " " << div << " times" << endl;

            // if(div == 0) continue;
            if(div < mi) {
                smi = mi;
                mi = div;
            } else if(div < smi) {
                smi = div;
            }

            if(mi == 0 and smi == 0) break;
        }

        // cerr << "smi of " << x << " is " << smi << endl;

        ans *= round(pow(x, smi));
    }

    cout << ans << endl;
}