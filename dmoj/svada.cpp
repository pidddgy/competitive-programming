#include <bits/stdc++.h>
#define ll long long
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int main() {
    ll T;
    cin >> T;

    int N;
    cin >> N;

    ll A[N+1];
    ll B[N+1];
    for(int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    int M;
    cin >> M;

    ll C[M+1];
    ll D[M+1];
    for(int i = 1; i <= M; i++)
        cin >> C[i] >> D[i];

    // mid = time spent on first group
    ll l = 1;
    ll r = T;
    ll mid = (l+r)/2;

    for(;;) {
        mid = (l+r)/2;
        ll f = 0; // number of coconuts found
        for(int i = 1; i <= N; i++) {
            f += (mid-A[i])/B[i];
            if(mid%B[i]==0) f++;
        }

        ll o = 0; // num of opened coconut
        for(int i = 1; i <= M; i++) {
            o += (T-mid-C[i])/D[i];
           // cout << "adding " << (T-mid-C[i])/D[i] << endl;
            if((T-mid)%D[i]==0) {
             //   cout << "adding one more"  << endl;
                o++;
            }
        // }
        // watch(l)
        // watch(r)
        // watch(mid)
        // watch(f)
        // cout<<endl;
        // watch(T-mid)
        // watch(o)
        // cout<<endl<<endl;

        if(f == o) {
            cout << mid << endl;
            return 0;
        } else if(f < o) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

}
}