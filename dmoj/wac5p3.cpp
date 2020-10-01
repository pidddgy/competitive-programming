// https://dmoj.ca/problem/wac5p3

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
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 200500;

int n;
int a[maxn];

// change when submitting
int DISTINCT_MAX = 460;

int cnt[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 1; i <= DISTINCT_MAX; i++) {
        int len = i*i;
        if(len > n) continue;

        int l = 0, r = len-1;

        int okelems = 0;
        for(int j = 1; j <= r; j++) {
            if(cnt[a[j]] == i-1) {
                okelems++;
            } else if(cnt[a[j]] == i) {
                okelems--;
            }

            cnt[a[j]]++;
        }

        while(r < n) {
            if(l > 0) {
                if(cnt[a[l]] == i+1) {
                    okelems++;    
                } else if(cnt[a[l]] == i) {
                    okelems--;
                }

                cnt[a[l]]--;
            }

            l++;
            r++;

            if(cnt[a[r]] == i-1) {
                okelems++;
            } else if(cnt[a[r]] == i) {
                okelems--;
            }
            
            cnt[a[r]]++;

            if(okelems == i) {
                ans++;
            }
        }

        for(int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
    }

    cout << ans << endl;
}

/*

it is guaranteed that we only have to check sequences with up to 450 distinct elements
each valid sequence has length equal to (# distinct elements) ^ 2

for i from 1 to 450
    check all sequences of length i**2


sliding window:
compute all elements from 1...len-1

add 1 to l, r

if in bounds check

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?