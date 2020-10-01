// https://codeforces.com/contest/1163/problem/C1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 55;
int n;
int x[maxn], y[maxn];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
map<pii, set<int>> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = 0, tot = 0;

    for(int i = 1; i <= n-1; i++) {
        for(int j = i+1; j <= n; j++) {
            int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];

            int a = y1-y2, b = x1-x2;           

            int g = gcd(a, b);
            a /= g;
            b /= g;

            if(a < 0 or (a == 0 and b < 0)) {
			    a = -a;
			    b = -b;
			}

            pii slope = {a, b};
            int c = a*x1 - b*y1;

            if(!mp[slope].count(c)) {
                tot++;
                mp[slope].emplace(c);
                ans += tot-(mp[slope].size());
            }
        }
    }

    cout << ans << endl;
}
