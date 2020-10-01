// Link

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

vector<int> ans;
int n, l, r;

bool intersect(int l1, int r1, int l2, int r2) {
	return min(r1, r2) >= max(l1, l2);
}

void calc(int sn, int en, int &ind) {
    if(sn == en) return;

    cerr << "ree " << ind << " " << ind + (2 * (en-sn)) << endl;
    if(intersect(l, r, ind, ind + (2 * (en-sn))-1)) {
        cerr << "intersect" << endl;
        for(int to = sn+1; to <= en; to++) {
            if(l <= ind and ind <= r) {
                ans.emplace_back(sn);
            }
            ind++;

            if(l <= ind and ind <= r) {
                ans.emplace_back(to);
            }
            ind++;
        }
    } else {
        ind += 2 * (en-sn);
    }

    calc(sn+1, en, ind);

    cerr << "hiiiiii" << endl;
    cerr << sn << " " << en << " " << ind << endl;
    if(sn == 1) {
        watch(ind)
        if(l <= ind and ind <= r) {
            ans.emplace_back(1);
        }
        ind++;
    }
}

void solve() {
    ans.clear();

    cin >> n >> l >> r;

    int init = 1LL;
    calc(1, n, init);

    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        solve();
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
