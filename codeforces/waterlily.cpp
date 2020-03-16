// http://codeforces.com/contest/1199/problem/B

#include <bits/stdc++.h>
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;


bool trng(ld a, ld b, ld c) 
{ 
    if (a + b <= c or a + c <= b or b + c <= a) 
        return false; 
    else
        return true; 
} 
  
int main() {
 
    ld H, L;
    cin >> H >> L;

    ld base = sqrt((H*H) + (L*L));
    watch(base)

    ld x = 0;

    while(!trng(x, x, base)) {
        x += 0.000001;
    }

    cout << x << endl;

    watch(x+x)
    watch(base)

    // ld l = 0.0;

    // // CHANGE THIS
    // ld r = 10.0;

    // ld mid = (l+r)/2;

    // while(!trng(base, mid, mid)) {
    //     mid = (l+r)/2;
    //     watch(l)
    //     watch(r)
    //     watch(mid);
    //     watch(base);
    //     watch(mid+mid)


    //     if(mid + mid <= base) {
    //         cout << "too small" << endl;
    //         l = mid;
    //     } else {
    //         cout << "too big" << endl;
    //         cout << "setting r to " << mid << endl;
    //         r = mid;
    //     }
    //     cout << endl;
        
    // }

    // cout << mid << endl;
}