// http://wcipeg.com/problem/wc184i1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int main() {
    #define int long long
    int A, B, C;
    cin >> A >> B >> C;

    int res = C;

    int thing = min(A, B);
    A -= thing;
    B -= thing;
    res += thing;

    if(A > B) {
        if(A < 3) {
            res += 1;
        }

        else {
            res += A / 3;
            if(A % 3 != 0) res += 1;
        }


    } else if (B > A) {
        res += B;
    }
    
    cout << res << endl;


}

