// https://codeforces.com/contest/730/problem/I

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 3005;
int n, p, s;

struct student {
    int ps, ss, ind;
};

struct Compare {
    bool operator()(student &l, student &r) {
        return pii(l.ps, l.ss) > pii(r.ps, r.ss); 
    }
};

student arr[maxn];
int a[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> s;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i].ps;
    }    

    for(int i = 1; i <= n; i++) {
        cin >> arr[i].ss;
    }

    for(int i = 1; i <= n; i++) {
        arr[i].ind = i;
    }

    sort(arr+1, arr+n+1, Compare());

    int r = 0;
    for(int i = 1; i <= p; i++) {
        a[i] = 1;
        r += arr[i].ps;
    }

    int np = 1;

    while(s--) {
        while(a[np] and np <= n) {
            np++;
        }

        int mac = 0, maind = -1;

        for(int i = 1; i <= n; i++) {
            // Ignore students already in sports team
            if(a[i] == 2) continue;

            int c = 0;
            if(a[i] == 0) {
                c = arr[i].ss;
            } else if(a[i] == 1) {
                c = (arr[i].ss - arr[i].ps) + arr[np].ps;
            }

            if(c > mac) {
                mac = c;
                maind = i;
            }
        }

        // If we took maind from programming team, replace maind with next highest
        if(a[maind] == 1) a[np] = 1;
        a[maind] = 2;
        r += mac;
    }

    vector<int> P, S;

    for(int i = 1; i <= n; i++) {
        if(a[i] == 1) {
            P.emplace_back(arr[i].ind);
        } else if(a[i] == 2) {
            S.emplace_back(arr[i].ind);
        }
    }

    cout << r << endl;
    for(int x: P) {
        cout << x << " ";
    }
    cout << endl;

    for(int x: S) {
        cout << x << " ";
    }
    cout << endl;
}
