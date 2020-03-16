// http://codeforces.com/contest/1207/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;

string s;
ll n, a, b;
// a -> gas pipline, b -> pillar

// assume that s[l] and s[r] are 1
ll f(ll l, ll r) {
    ll down = 0;
    ll stay = 0;
    
    // watch(a)
    // watch(b)

    // cout << "we need " << (4) + (r-l-2) << " pipeline to go down " << endl;
    // cout << "we need " << (r-l) << " pipeline to stay " << endl;

    // cout << "we need " << (r-l-1) + 2 << " pillar to go down" << endl;
    // cout << "we need " <<  (r-l)*2 << " pillar to stay" << endl;

    // pipeline
    down += ((4) + (r-l-2)) * a;

    // pillar
    down += ((r-l-1) + 2) * b;

    stay += ((r-l)) * a;
    stay += ((r-l)*2) * b;

    // watch(down)
    // watch(stay)

    return min(down, stay);

}

int main() {
    ll T;
    cin >> T;
    while(T--) {
        cin >> n >> a >> b;

        cin >> s;
        s = "."+s;
        deque<ll> points;
        bool valid = true;
        for(ll i = 1; i <= n; i++) {
            if(s[i] == '1' and (s[i-1] == '0' or s[i+1] == '0')) {
                if(valid) {
                    points.emplace_back(i-1);
                    valid = false;
                }
                valid = !valid;
            }

        }

        points.pop_front();
        for(auto x: points) {
            cout << x << endl;
        }

        // ll P = points.size();
        // ll ans = 0;

        // ans += (points[0] - 1)*a;
        // ans += (points[0] * b);

        // ans += 2*a;
        // ans += 2*b;
        
        // cout << "used " << (points[0] - 1)+2 << " line " << endl;
        // cout << "used " << ans << " to get to  first point " << endl;

        // for(ll i = 0; i < points.size()-1; i++) {
        //     ans += f(points[i], points[i+1]);
        // }

        // ans += 2*a;
        // ans += ((n - points[P-1])-1) * a;

        // ans += (n-points[P-1]) * b;

        // cout << ans << endl; 





    }
}