// https://codeforces.com/contest/519/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

map<char, int> x;
int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(char chr: string("abcdefghijklmnopqrstuvwxyz")) {
        cin >> x[chr];
    }    

    string s;
    cin >> s;

    int n = s.size();

    s = "."+s;

    ll ans = 0;

    for(char chr: string("abcdefghijklmnopqrstuvwxyz")) {
        map<ll, int> cnt;
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == chr) {
                ans += cnt[sum];

                cnt[sum+x[s[i]]]++;
            }
            sum += x[s[i]];
        }
    }

    cout << ans << endl;
}