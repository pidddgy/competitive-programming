// https://codeforces.com/contest/837/problem/C

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define scope for(int scope = 1; scope <= 1; scope++)
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;

    pii arr[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }

    int ans = 0;
    scope {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;

                pii f = arr[i];
                pii s = arr[j];

                // if(f == s) continue;

                int rem1x = a-f.fi;
                int rem1y = b-f.se;

                watch(rem1x)
                watch(rem1y)

                watch(s.fi)
                watch(s.se)
                if(rem1x < 0) continue;
                if(rem1y < 0) continue;
        
                if(s.fi <= rem1x and s.se <= b) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } else if(s.fi <= a and s.se <= rem1y) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } else if (s.fi <= rem1y and s.se <= a) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } else if (s.fi <= b and s.se <= rem1x) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } 

            }
        }
    }

    swap(a, b);

    scope {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;



                pii f = arr[i];
                pii s = arr[j];

                // if(f == s) continue;


                int rem1x = a-f.fi;
                int rem1y = b-f.se;

                if(rem1x < 0) continue;
                if(rem1y < 0) continue;
        
                if(s.fi <= rem1x and s.se <= b) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } else if(s.fi <= a and s.se <= rem1y) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } else if (s.fi <= rem1y and s.se <= a) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } else if (s.fi <= b and s.se <= rem1x) {
                    ans = max(ans, (f.fi*f.se) + (s.fi*s.se));
                } 

            }
        }
    }

    assert(ans <= a*b);
    cout << ans << endl;



}