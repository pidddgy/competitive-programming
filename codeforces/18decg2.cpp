#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define ll long long
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void solve() {
    
}

const int maxn = 100500;
const int maxv = (int)1e6+5;



// map<vector<int>, int> cnt[6];

int cnt1[maxv];
map<int, int> cnt2[maxv];
map<int, map<int, int>> cnt3[maxv];
map<int, map<int, map<int, int>>> cnt4[maxv];
map<int, map<int, map<int, map<int, int>>>> cnt5[maxv];

int a[5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    ll n;
    // cin >> n;
    scan(n);

    ll ans = 0;
    for(int i = 1; i <= n; i++) {

        for(int j = 0; j < 5; j++) {
            // cin >> a[j];
            scan(a[j]);
        }
        sort(a, a+5);

        for(int mask = 1; mask < (1<<5); mask++) {
            vector<int> v;
            int t = 0;
            for(int j = 0; j < 5; j++) {
                if(!(mask & (1 << j))) continue;

                v.emplace_back(a[j]);
                t++;
            }

            if(t % 2 == 1) {
                if(t == 1) ans += cnt1[v[0]]++;
                if(t == 3) ans += cnt3[v[0]][v[1]][v[2]]++;
                if(t == 5) ans += cnt5[v[0]][v[1]][v[2]][v[3]][v[4]]++;
            } else {
                if(t == 2) ans -= cnt2[v[0]][v[1]]++;
                if(t == 4) ans -= cnt4[v[0]][v[1]][v[2]][v[3]]++;
            }

        }
    }

    ll trng = (ll)n*((ll)n-1);
    trng /= 2;
    
    ll out = trng - (ll)ans;
    cout << out << endl;
}

/*
1 550 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
