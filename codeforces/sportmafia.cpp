// http://codeforces.com/contest/1195/problem/B

#include <bits/stdc++.h>
#define ll long long
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
ll T(ll a) {
    return a*(a+1)/2;
}
int main() {

    #define int long long

    int n, k;
    cin >> n >> k;

    int l = 1;
    int r = n;

    // i = how many times did she eat
    
    while (l <= r) {
        int i = (l+r)/2;
     //   cout << "she ate " << i << " times "<< endl;
   //     cout << "she put in " << n-i << " times " << endl;
       // watch(T(n-i))

        int result = (T(n-i) - i);
        
        // if too small, then she must have eaten less
        if(result < k) {
            r = i-1;
        } else if(result > k) {
            // if too big, she must have eaten more
            l = i+1;
        } else {
            cout << i << endl;
            return 0;
        }

   //     cout << endl;
    }
    
    cout << (l+r)/2 << endl;
}