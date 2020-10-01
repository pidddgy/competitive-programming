// https://codeforces.com/contest/777/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

int N;
const int maxn = 500500;

string a[maxn];
int keep[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i].erase(a[i].begin());
    }

    keep[N] = a[N].size();

    for(int i = N-1; i >= 1; i--) {
        // How much to keep?
        int l = 0;
        int r = a[i].size();

        while(l <= r) {
            int m = (l+r)/2;

            string S;
            for(int j = 1; j <= m; j++) {
                S += a[i][j-1];
            }

            // If still greater than i+1, remove more
            if(lexicographical_compare(all(a[i+1]), all(S))) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        string S;
        for(int j = 1; j <= r; j++) {
            S += a[i][j-1];
        }
        a[i] = S;
        keep[i] = r;
    }

    for(int i = 1; i <= N; i++) {
        cout << "#";
        for(int j = 0; j < keep[i]; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
