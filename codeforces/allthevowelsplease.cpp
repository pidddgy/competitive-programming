// http://codeforces.com/contest/1166/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

char a[] = {'a', 'e', 'i', 'o', 'u'};
int main() {
    int k;
    cin >> k;
 //   watch(k)

    for(int i = 1; i <= k; i++) {
       // watch(i)
        if(k%i==0) {
           // cout << "HI" << endl;
      //      watch(i)
            if(i >= 5 && k/i >= 5) {
                int n = i;
                int m = k/i;

                for(int ii = 0; ii < n; ii++) {
                    for(int jj = 0; jj < m; jj++) {
                        cout << a[(ii+jj)%5];
                    }
                }
                return 0;
            }
        }
    }

    cout << -1;
}
