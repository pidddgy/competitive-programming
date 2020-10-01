// https://codeforces.com/contest/1250/problem/B

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

const int MAXN = 500500;
const int MAXK = 8005;

int n, k;

// cardinality of all teams
int car[MAXK];

int go(int s) {
    cerr << "currently trying " << s << endl;
    multiset<int> S;
    for(int i = 1; i <= k; i++) {
        cerr << "emplacing " << car[i] << endl;
        S.emplace(car[i]);
    }
    
    int r = 0;
    while(sz(S)) {
        int a = *S.begin();
        S.erase(S.begin());
        
        assert(s >= a);

        cerr << "taking " << a << endl;

        int rem = s-a;
        watch(rem)

        if(sz(S) and (*S.begin() <= rem)) {
            auto ptr = S.upper_bound(rem);
            while((ptr == S.end()) or (*ptr) > rem) {
                ptr--;
            }

            cerr << "taking " << *ptr << endl;
            S.erase(ptr);

        }

        r++;
    }

    return s*r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        car[x]++;
    }

    sort(car+1, car+k+1);

    int ans = 1e18;

    for(int i = 0; i <= k; i += 2) {
        int ma = -1e18;

        for(int j = 1; j <= i/2; j++) {
            ma = max(ma, car[j] + car[i-j+1]);
        }

        for(int j = i+1; j <= k; j++) {
            ma = max(ma, car[j]);
        }

        ans = min(ans, ma*(i/2 + k-i));
    }

    cout << ans << endl;
}

/*
4 000 000 000
we either want to minimize s as hard as possible or minimize r as hard as possible

to check we can push all the elements into a set. repeatedly match the smallest element with the biggest element possible

to minimize s set s = max team size
to minimize r set s = biggest team size + smallest team size

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
