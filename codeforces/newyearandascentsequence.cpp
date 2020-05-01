// https://codeforces.com/contest/1284/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    #define pii pair<int, int>
    #define fi first
    #define se second
    #define watch(x) cerr << (#x) << " is " << (x) << endl;
    #define cerr if(false) cerr
    int n;
    cin >> n;

    vector<pii> a;
    for(int i = 1; i <= n; i++) {
        int l;
        cin >> l;

        vector<int> seq;
        for(int j = 1; j <= l; j++) {
            int _;
            cin >> _;

            cerr << "sdfdsfdsf " << _ << endl;

            seq.emplace_back(_);
        }

        vector<int> cpy = seq;
        reverse(cpy.begin(), cpy.end());

        if(is_sorted(cpy.begin(), cpy.end())) {
            cerr << "emplacing back " << seq[0] << "," << seq[seq.size()-1] << endl;
            a.emplace_back(seq[0], seq[seq.size()-1]);
        }
    }

    sort(a.begin(), a.end());

    int ans = n*n;
    watch(ans)
    for(pii x: a) {
        cerr << "currently on " << x.fi << " " << x.se << endl;
        int leq = upper_bound(a.begin(), a.end(), pii(x.se+1, INT_MIN)) - a.begin();
        watch(leq)
        ans -= leq;
        cerr << endl;
    }

    cout << ans << endl;
}