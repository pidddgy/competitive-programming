// https://codeforces.com/problemset/problem/849/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define ld long double
#define pld pair<ld, ld>
#define fi first
#define se second
const int maxn = 1005;

int n;
int a[maxn];
bool vis[maxn];

pld slint(int x, int y, int a, int b) {
    ld slope = (ld)(b-y) / (a-x);
    ld intercept = (ld)y-(slope*(ld)x);

    return pld(slope, intercept);
}

bool check(ld x, ld b) {
    cerr << "checking " << x << "," << b << endl;
    for(int i = 0; i < maxn; i++) vis[i] = false;

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if((ld)a[i] == (ld)i*x + b) {
            vis[i] = true;
            cnt++;
        }
    }

    if(cnt == n) {
        cerr << "failed 123" << endl;
        return false;
    }

    if(cnt == n-1) return true;

    vector<int> posns;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            posns.emplace_back(i);
            vis[i] = true;
        }

        if(posns.size() >= 2) break;
    }

    pld slin = slint(posns[0], a[posns[0]], posns[1], a[posns[1]]);
    ld slope = slin.fi;
    ld intercept = slin.se;

    if(!(slope == x and intercept != b)) {
        cerr << "failed" << endl;
        return false;
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            pld curslin = slint(posns[0], a[posns[0]], i, a[i]);
            ld curslope = curslin.fi;
            ld curintercept = curslin.se;

            if(curslope == slope and curintercept == intercept) {
                vis[i] = true;
            } else {
                cerr << "failed on " << i << endl;
                return false;
            }
        }
    } 

    cerr << "returning true" << endl;
    return true;

}

signed main() {
    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // pld test = slint(69, 420, 69, 420);
    // cout << test.fi << "," << test.se << endl;
    bool good = false;

    pld temp1 = slint(1, a[1], 2, a[2]);
    pld temp2 = slint(1, a[1], 3, a[3]);
    pld temp3 = slint(2, a[2], 3, a[3]);

    good |= check(temp1.fi, temp1.se);
    good |= check(temp2.fi, temp2.se);
    good |= check(temp3.fi, temp3.se);
    
    watch(temp3.fi)
    watch(temp3.se)
    if(check(temp1.fi, temp1.se)) {
        cerr << "is good" << endl;
        watch(temp1.fi)
        watch(temp1.se)
    }

    if(good) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}