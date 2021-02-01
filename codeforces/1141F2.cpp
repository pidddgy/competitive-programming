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

const int maxn = 2000;

int n;
int a[maxn];
map<int, int> cnt, last;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // sum of each block
    int per = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = i; j >= 1; j--) {
            sum += a[j];

            cerr << j << " " << i << " -> " << sum << endl;
            watch(last[sum])

            if(j > last[sum]) {
                last[sum] = i;
                cnt[sum]++;
            }

            if(cnt[sum] > cnt[per]) per = sum;
        }
    }

    int ind = 1;
    cout << cnt[per] << endl;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = i; j >= ind; j--) {
            sum += a[j];

            if(sum == per) {
                cout << j << " " << i << endl;
                ind = i+1;
                break;
            }
        }
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
