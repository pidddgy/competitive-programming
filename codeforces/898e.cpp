// https://codeforces.com/contest/898/problem/E

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

pii closest(int n) {
    int l = 0;
    int r = 1000000;

    pii res;
    while(l <= r) {
        int m = (l+r)/2;

        if(m*m < n) {
            res.fi = m*m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    l = 0;
    r = 1000000;
    while(l <= r) {
        int m = (l+r)/2;

        if(m*m > n) {
            res.se = m*m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    return res;
}

set<int> squares;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <= 100000; i++) {
        squares.emplace(i*i);
    }

    int n;
    cin >> n;

    int a[n+1];
    int sq = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(squares.count(a[i])) {
            sq++;
        }
    }

    watch(sq)

    sort(a+1, a+n+1, greater<int>());
    int ans = 0;
    vector<int> posscosts;
    for(int i = 1; i <= n; i++) {
        cerr << "on " << i << endl;
        watch(a[i])
        watch(squares.count(a[i]))
        if(sq > (n/2)) {
            cerr << "hi" << endl;
            if(squares.count(a[i])) {
                cerr << "hi" << endl;
                if(a[i] == 0) {
                    cerr << "adding 2" << endl;
                    ans += 2;
                } else {
                    cerr << "adding" << endl;
                    ans++;
                }
                sq--;
            }
        } else if(sq < n/2) {
            if(!squares.count(a[i])) {
                pii sqs = closest(a[i]);
                cerr << "on " << a[i] << endl;
                cerr << "closest squares at " << sqs.fi << "," << sqs.se << endl;
                posscosts.emplace_back(min(a[i]-sqs.fi, sqs.se-a[i]));
                cerr << "emplacing " << (min(a[i]-sqs.fi, sqs.se-a[i])) << endl;
            }
        }
    }

    sort(posscosts.begin(), posscosts.end());
    for(int i = 0; i < (n/2)-sq; i++) {
        ans += posscosts[i];
    }

    cout << ans << endl;
}