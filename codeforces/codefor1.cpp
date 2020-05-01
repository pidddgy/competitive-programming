// https://codeforces.com/contest/768/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int n, l, r;

int leaf(int n) {
    int res = 1;
    while(n > 1) {
        res *= 2;
        n /= 2;
    }

    return res;
}

signed main() {
    cin >> n >> l >> r;

    int nodes = (leaf(n)*2)-1;
    int pos = (nodes+1)/2;
    int ans = 0;
    // target == i
    for(int target = l; target <= r; target++) {
        int curInd = pos;
        int curVal = n;
        int change = pos/2;
        
        watch(target)
        for(;;) {
            // watch(curInd)
            // watch(curVal)
            // watch(change)
            if(target > curInd) {
                curInd += change;
                change /= 2;
                curVal /= 2;
            } else if(target < curInd) {
                curInd -= change;
                change /= 2;
                curVal /= 2;
            } else if(target == curInd) {
                // cerr << target << " is " << curVal%2 << endl;
                // cerr << "breaking" << endl;
                ans += (curVal % 2) == 1;
                break;
            }
            cerr << endl;
        }

        cerr << "-----" << endl;
    }

    cout << ans << endl;
}