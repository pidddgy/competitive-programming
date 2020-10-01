// Link

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g = lcm(a[0], a[1]);

    for(int i = 0; i < 3000000; i++) {
        int l = mt()%n;
        int r = mt()%n;
        
        while(l == r) {
            r = mt()%n;
        }

        g = gcd(g, lcm(a[l], a[r]));
    }

    cout << g << endl;
}
