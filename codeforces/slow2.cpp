#include <bits/stdc++.h> 
using namespace std;
int main () {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    auto solve = [&] () {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = i+1; k <= j; k++) if (a[k] <= a[k-1]) goto bad;
                ret = max(ret, j - i + 1);
                bad:;
            } 
        }
        return ret;
    };
    int ret = 1;
    for (int i = 0; i < n; i++) { //change a[i]
        int temp = a[i];
        for (int rep : {i+1 < n ? a[i+1] - 1 : -1,i > 0 ? a[i-1] + 1 : -1,i+1<n&&i>0?(a[i-1]+a[i+1])/2:-1}) {
            if (rep == -1) continue;
            a[i] = rep;
            ret = max(ret,solve());
        }
        a[i] = temp;
    }
    printf ("%d\n",ret);
    return 0;
}