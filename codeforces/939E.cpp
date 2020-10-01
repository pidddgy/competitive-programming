// https://codeforces.com/contest/939/problem/E

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 500500;

int n = 0;

int a[maxn];
int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int x;
            cin >> x;

            n++;
            a[n] = x;
            psa[n] = psa[n-1]+x;
        } else if(t == 2) {
            int l = 0;
            int r = n-1;
            int lgood = -1;

            // Binary search for rightmost element that has higher answer than previous
            while(l <= r) {
                int m = (l+r)/2;
                if(m == 0) {
                    l = m+1;
                    lgood = m;
                    continue;
                }

                cerr << "trying " << m << endl;

                int sum = psa[m] + a[n];
                ld avg = sum / (ld)(m+1);

                int sum2 = psa[m-1] + a[n];
                ld avg2 = sum2 / (ld)(m);

                watch(sum)
                watch(m+1)
                watch(avg)
                watch(avg2)

                ld ans = a[n]-avg, ans2 = a[n]-avg2;

                watch(ans)
                watch(ans2)

                // If is better than last
                if(ans > ans2) {
                    lgood = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            watch(lgood)
            ld avg = (psa[lgood] + a[n]) / (ld)(lgood+1);
            cerr << "avg is " << avg << endl;
            ld ans = a[n] - avg;

            cout << ans << endl;
            cerr << endl;
        }
    }    
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?