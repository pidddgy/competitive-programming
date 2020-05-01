// https://codeforces.com/contest/283/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
#define ld long double

const int maxn = 200500;

int bit1[maxn];
int bit2[maxn];
int n;
ld curPos = 1;

void add(int *arr, int idx, int val) {
    for(int i = idx; i <= maxn-5; i += i & -i) {
        arr[i] += val;
    }
}

void rangeAdd(int l, int r, int val) {
    add(bit1, l, val);
    add(bit1, r+1, -val);
    add(bit2, l, val*(l-1));
    add(bit2, r+1, -val*r);
}

int sum(int *arr, int idx) {
    int res = 0;
    for(int i = idx; i >= 1; i -= i & -i) {
        res += arr[i];
    }

    return res;
}

int prefSum(int idx) {
    return (sum(bit1, idx)*idx) - sum(bit2, idx);
}

int rangeSum(int l, int r) {
    watch(prefSum(r))
    watch(prefSum(l-1))
    return prefSum(r) - prefSum(l-1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int op = 1; op <= n; op++) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, x;
            cin >> a >> x;
            
            rangeAdd(1, a, x);
        } else if(t == 2) {
            int k;
            cin >> k;

            curPos++;
            rangeAdd(curPos, curPos, k);
        } else if(t == 3) {
            int curVal = rangeSum(curPos, curPos);
            rangeAdd(curPos, curPos, -curVal);
            curPos--;
        }

        ld sum = prefSum(curPos);
        cout << fixed << setprecision(10) << sum/curPos << endl;
    }

    
}