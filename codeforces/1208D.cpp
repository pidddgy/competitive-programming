// https://codeforces.com/contest/1208/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

int s[maxn];
int seg[4*maxn];

void upd(int pos, int val) {
    pos += n;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l += n;
    r += n;
    int res = 0;

    while(l <= r) {
        if(l%2==1) res += seg[l++];
        if(r%2==0) res += seg[r--];

        l /= 2;
        r /= 2;
    }

    return res;
}

int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        upd(i, i);
    }

    for(int i = n; i >= 1; i--) {
        int l = 1, r = n;
        int lgood = -1;
        // bsearch for first element w sum > s[i]
        while(l <= r) {
            int mid = (l+r)/2;

            int ree = query(1, mid);

            if(ree > s[i]) {
                lgood = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        assert(lgood != -1);
        assert(query(1, lgood-1) == s[i]);

        ans[i] = lgood;
        upd(lgood, 0);
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

if goes up then a goes up
else a goes down

we can find for each index if it goes up or down

fix ending element

go from 1...n adding until we reach s[n]



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
