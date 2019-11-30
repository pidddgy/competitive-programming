// https://dmoj.ca/problem/year2018p3

#include <bits/stdc++.h>
#define ll long long
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int N, K, M;

bool ok(vector<ll> A, ll height) {
    int D[N+1]; fill(D, D+N+1, 0);
    ll need = 0;

    for(int i = 1; i <= N; i++) {
        D[i] += D[i-1];
        A[i] += D[i];

        if(A[i] < height) {
            ll diff = height-A[i];
          //  cout << "diff between " << height << " and " << i << " is " << diff << endl;
            need += diff;
         //   cout << "need is now " << need << endl;
            D[i] += diff;

            if(i+M <= N)
                D[i+M] -= diff;
        }
    }

    // if(need <= K) {
    //     cout << "returning true" << endl;
    // } else {
    //     cout << "return false " << endl;
    // }

    // cout << "need is " << need << endl;
    // cout << "k is " << K << endl;
    return(need <= K);
}

int main() {
    cin >> N >> M >> K;

    ll l = 2147483647;
    ll r = -2147483647;

    vector<ll> A(N+1);
    for(int i = 1; i <= N; i++){
        ll x; cin >> x;
        A[i] = x;
        l = min(l, x);
        r = max(r, x);
    }   

    r += K+1;

    while(l <= r) {
       // watch(l)
       // watch(r)
        ll mid = (l+r)/2;
        if(ok(A, mid)){
          //  cout << "HI" << endl;
            l = mid+1;
        }
        else r = mid-1;
     //   cout << endl;
    }

    cout << r << endl;

}
