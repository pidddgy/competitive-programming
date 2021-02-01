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
int cock[maxn];
pii cute[maxn];
int hugs[maxn];

int wee[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cock[i];
        hugs[i] = cock[i];
        cute[i] = pii(cock[i], i);
    }

    sort(hugs+1, hugs+n+1);
    sort(cute+1, cute+n+1);
    reverse(cute+1, cute+n+1);

    int l = 0;
    int r = 1e18;

    int ans = 69;
    while(l <= r) {
        int shit = (l+r)/2;

        vector<int> v;
        for(int i = 1; i <= n; i++) wee[i] = 1e18;

        for(int i = 1; i <= n; i++) {
            cerr << "emplacing " << cute[i].se << endl;
            v.emplace_back(cute[i].se);

            if(i == n or cute[i].fi-cute[i+1].fi > shit) {
                for(int x: v) {
                    cerr << "setting " << x << " to " << cute[i].fi << endl;
                    wee[x] = cute[i].fi;
                }
                v.clear();
            }
        }

        cerr << "trying " << shit << endl;
        bool bad = false;
        for(int i = 1; i <= n; i++) {
            cerr << cock[i] << " can go down to " << wee[i] << endl;
            if(wee[i] > hugs[i]) {
                bad = true;
            } 
        }

        if(!bad) {
            ans = shit;
            r = shit-1;
        } else {
            l = shit+1;
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*

iterate left -> right

we only need to go down

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?