// https://codeforces.com/problemset/problem/493/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long

const int maxnm = 200500;

int a[maxnm], b[maxnm];
int n, m;
set<int> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        S.emplace(a[i]);
        S.emplace(a[i]-1);
        S.emplace(b[i]+1);
    }

    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        S.emplace(b[i]);
        S.emplace(b[i]-1);
        S.emplace(b[i]+1);
    }

    S.emplace(0);
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    int aans = -INT_MAX;
    int bans = INT_MAX;
    for(int x: S) {
        // bsearch num of two pointers
        watch(x)
        int l = 1;
        int r = n;
        int cntn = 0;
        while(l <= r) {
            int md = (l+r)/2;

            if(a[md] < x) {
                cntn = md;
                l = md+1;
            } else {
                r = md-1;
            }
        }

        l = 1;
        r = m;
        int cntm = 0;

        while(l <= r) {
            int md = (l+r)/2;

            if(b[md] < x) {
                cntm = md;
                l = md+1;
            } else {
                r = md-1;
            }
        }

        int asc = cntn*2 + (n-cntn)*3;
        int bsc = cntm*2 + (m-cntm)*3;

        watch(cntn)
        watch(cntm)
        watch(asc)
        watch(bsc)

        cerr << endl;

        if(asc - bsc > aans - bans) {
            aans = asc;
            bans = bsc;
        } else if((asc - bsc == aans - bans) and asc > aans) {
            aans = asc;
            bans = bsc;
        }
    }

    cout << aans << ":" << bans << endl;
}