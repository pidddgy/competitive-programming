// http://codeforces.com/contest/1213/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int a[N+1];
        for(int i = 1; i <= N; i++) cin >> a[i];

        int bad = 0;
        int mi = a[N]; 
        for(int i = N-1; i >= 1; i--) {
            // watch(a[i])
            // watch(mi)
            if(a[i] < mi) {
                mi = a[i];
            }
            if(a[i] > mi) bad++;


            // cout<<endl;
        }

        cout << bad << endl;
    }
}