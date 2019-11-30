// https://dmoj.ca/problem/cpc19c1p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;
int main() {
    int N;
    ll K;
    cin >> N >> K;

    ll a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a+N);

    int cur = 0;
    int ans = 0;
    for(int i = 1; i < N; i++) {
        assert(cur <= N-1);
      //  watch(i)
    //    watch(a[i])
        if(a[i]-a[cur] > K) {
  //          cout << "too big" << endl;
       //     watch(a[i]-a[cur])
    //        cout << "cur was " << cur << endl;
            while(a[i]-a[cur] > K) {
                cur++;
            }
          //  cout << "an eligible range is " << cur << " " << i << endl;
            ans = max(ans, i-cur+1);
        //    cout << "cur is now " << cur << endl;
        } else {
           // cout << "an eligible range is " << cur << " " << i << endl;
            ans = max(ans, i-cur+1);
        }
     //   cout << endl;
    }

    cout << ans << endl;

}
