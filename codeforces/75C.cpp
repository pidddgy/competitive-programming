// https://codeforces.com/contest/75/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int g = gcd(a, b);

    map<int, int> seen;
    vector<int> divisors;
    for(int i = 1; i < min((int)sqrt(g)+5, g); i++) {
        if(g%i==0) {
            if(!seen[g/i] or !seen[i]) {
                seen[i] = true;
                seen[g/i] = true;

                divisors.emplace_back(i);
                divisors.emplace_back(g/i);
            }
        }
    }

    divisors.emplace_back(1);
    sort(divisors.begin(), divisors.end());

    for(int x: divisors) {
        cerr << x << " ";
    }
    cerr << endl;

    int q;
    cin >> q;

    while(q--) {
        int low, high;
        cin >> low >> high;

        if(divisors.empty()) {
            cout << -1 << endl;
            continue;
        }

        int l = 0;
        int r = divisors.size()-1;
        int lastgood = -1;
        while(l <= r) {
            int m = (l+r)/2;

            if(divisors[m] <= high) {
                l = m+1;
                lastgood = m;
            } else {
                r = m-1;
            }
        }

        if(lastgood == -1 or divisors[lastgood] < low or divisors[lastgood] > high) cout << -1 << endl;
        else {
            cout << divisors[lastgood] << endl;
        }
    }


}