// https://codeforces.com/contest/1262/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int main() {
    #define int long long
    #define endl '\n'
    #define pii pair<int ,int>
    #define fi first
    #define se second
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        pii a[N+1];
        int biggest = 0;
        int smallest = LONG_MAX;
        for(int i = 1; i <= N; i++) {
            cin >> a[i].fi >> a[i].se;
            biggest = max(biggest, a[i].fi);
            biggest = max(biggest, a[i].se);
        }


        sort(a+1, a+N+1);

        int l = max(a[1].se, a[1].fi);

        int L = 1;
        int R = biggest;
        int lastgoodm = -1;

        // watch(biggest)

        while(L <= R) {
            int M = (L+R)/2;
            // watch(M);
            bool good = true;
            for(int i = 1; i <= N; i++) {
                if(a[i].fi > M) {
                    good = false;
                }
            }

            if(good) {
                R = M-1;
                lastgoodm = M;
            }
            else L = M+1;
        }


        // watch(lastgoodm)


        L = 1;
        R = lastgoodm;
        int lastgood = -1;

        while(L <= R) {
            int M = (L+R)/2;
            // watch(M);
            bool good = true;
            for(int i = 1; i <= N; i++) {
                if(a[i].se < M) {
                    good = false;
                }
            }

            if(good) {
                L = M+1;
                lastgood = M;
            }
            else R = M-1;
        }

        // assert(lastgoodm != -1);
        // watch(lastgood)
        
        cout << abs(lastgoodm-lastgood) << endl;




        
        

    }
}
