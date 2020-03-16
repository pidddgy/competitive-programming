// https://codeforces.com/contest/747/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;

int a[200];
int main() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= q; i++) {
        cerr << "aa" << endl;
        int t;
        int k;
        int d;
        cin >> t >> k >> d;

        int vcnt = 0;
        for(int j = 1; j <= n; j++) {
            if(a[j] <= t) {
                vcnt++;
            }
        }

        watch(vcnt)
        if(vcnt >= k) {
            int sum = 0;
            int used = 0;
            for(int j = 1; j <= n; j++) {
                if(a[j] <= t) {
                    cerr << "using " << j << endl;
                    watch(a[j])
                    used++;
                    sum += j;
                      cerr << "setting " << j << " to " << t+d << endl;
                a[j] = t+d;
                }   

              

                if(used == k) {
                    cerr << "breaking" << endl;
                    cerr << "used is " << used << endl;
                    break;
                }
            }

            cerr << "i is " << i << endl;
            cout << sum << endl;
        } else {
            cout << -1 << endl;
        }

        cerr << endl;
    }
}